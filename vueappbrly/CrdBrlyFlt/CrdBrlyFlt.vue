<template>
	<v-container v-if="initdone">
		<PnlBrlyFltList
			v-on:request="handleRequest"
			ref="PnlBrlyFltList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyFltRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyFltRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyFltList from './PnlBrlyFltList';
	import PnlBrlyFltRec from './PnlBrlyFltRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyFlt',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyFltList,
			PnlBrlyFltRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyFlt.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfBrlyFlt) this.continf = dpcheng.ContInfBrlyFlt;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyFlt) this.statapp = dpcheng.StatAppBrlyFlt;
				if (dpcheng.StatShrBrlyFlt) this.statshr = dpcheng.StatShrBrlyFlt;
				if (dpcheng.TagBrlyFlt) {
					Brly.unescapeBlock(dpcheng.TagBrlyFlt);
					this.tag = dpcheng.TagBrlyFlt;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyFltList.handleReply(obj);
					else this.$refs.PnlBrlyFltRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyFltData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyFltList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyFltRec.handleUpdate(obj);
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
