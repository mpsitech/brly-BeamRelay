<template>
	<v-container v-if="initdone">
		<PnlBrlyUsrList
			v-on:request="handleRequest"
			ref="PnlBrlyUsrList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyUsrRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyUsrRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyUsrList from './PnlBrlyUsrList';
	import PnlBrlyUsrRec from './PnlBrlyUsrRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyUsr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyUsrList,
			PnlBrlyUsrRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyUsr.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfBrlyUsr) this.continf = dpcheng.ContInfBrlyUsr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyUsr) this.statapp = dpcheng.StatAppBrlyUsr;
				if (dpcheng.StatShrBrlyUsr) this.statshr = dpcheng.StatShrBrlyUsr;
				if (dpcheng.TagBrlyUsr) {
					Brly.unescapeBlock(dpcheng.TagBrlyUsr);
					this.tag = dpcheng.TagBrlyUsr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyUsrList.handleReply(obj);
					else this.$refs.PnlBrlyUsrRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyUsrData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyUsrList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyUsrRec.handleUpdate(obj);
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
