<template>
	<v-container v-if="initdone">
		<PnlBrlyPtyList
			v-on:request="handleRequest"
			ref="PnlBrlyPtyList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyPtyRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyPtyRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyPtyList from './PnlBrlyPtyList';
	import PnlBrlyPtyRec from './PnlBrlyPtyRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyPty',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyPtyList,
			PnlBrlyPtyRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyPty.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfBrlyPty) this.continf = dpcheng.ContInfBrlyPty;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyPty) this.statapp = dpcheng.StatAppBrlyPty;
				if (dpcheng.StatShrBrlyPty) this.statshr = dpcheng.StatShrBrlyPty;
				if (dpcheng.TagBrlyPty) {
					Brly.unescapeBlock(dpcheng.TagBrlyPty);
					this.tag = dpcheng.TagBrlyPty;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyPtyList.handleReply(obj);
					else this.$refs.PnlBrlyPtyRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyPtyData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyPtyList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyPtyRec.handleUpdate(obj);
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
