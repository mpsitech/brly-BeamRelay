<template>
	<v-container v-if="initdone">
		<PnlBrlyPrsList
			v-on:request="handleRequest"
			ref="PnlBrlyPrsList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyPrsRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyPrsRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyPrsList from './PnlBrlyPrsList';
	import PnlBrlyPrsRec from './PnlBrlyPrsRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyPrs',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyPrsList,
			PnlBrlyPrsRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyPrs.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppBrlyInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfBrlyPrs) this.continf = dpcheng.ContInfBrlyPrs;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyPrs) this.statapp = dpcheng.StatAppBrlyPrs;
				if (dpcheng.StatShrBrlyPrs) this.statshr = dpcheng.StatShrBrlyPrs;
				if (dpcheng.TagBrlyPrs) {
					Brly.unescapeBlock(dpcheng.TagBrlyPrs);
					this.tag = dpcheng.TagBrlyPrs;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyPrsList.handleReply(obj);
					else this.$refs.PnlBrlyPrsRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyPrsData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyPrsList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyPrsRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxBrlyVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
