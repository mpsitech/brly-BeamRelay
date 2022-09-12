<template>
	<v-container v-if="initdone">
		<PnlBrlyOprList
			v-on:request="handleRequest"
			ref="PnlBrlyOprList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyOprRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyOprRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyOprList from './PnlBrlyOprList';
	import PnlBrlyOprRec from './PnlBrlyOprRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyOpr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyOprList,
			PnlBrlyOprRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyOpr.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfBrlyOpr) this.continf = dpcheng.ContInfBrlyOpr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyOpr) this.statapp = dpcheng.StatAppBrlyOpr;
				if (dpcheng.StatShrBrlyOpr) this.statshr = dpcheng.StatShrBrlyOpr;
				if (dpcheng.TagBrlyOpr) {
					Brly.unescapeBlock(dpcheng.TagBrlyOpr);
					this.tag = dpcheng.TagBrlyOpr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyOprList.handleReply(obj);
					else this.$refs.PnlBrlyOprRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyOprData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyOprList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyOprRec.handleUpdate(obj);
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
