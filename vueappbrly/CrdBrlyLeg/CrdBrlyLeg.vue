<template>
	<v-container v-if="initdone">
		<PnlBrlyLegList
			v-on:request="handleRequest"
			ref="PnlBrlyLegList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyLegRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyLegRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyLegList from './PnlBrlyLegList';
	import PnlBrlyLegRec from './PnlBrlyLegRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyLeg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyLegList,
			PnlBrlyLegRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyLeg.mounted() with scrJref = " + this.scrJref);

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
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfBrlyLeg) this.continf = dpcheng.ContInfBrlyLeg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyLeg) this.statapp = dpcheng.StatAppBrlyLeg;
				if (dpcheng.StatShrBrlyLeg) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrBrlyLeg.scrJrefDlgnew != "");
						dlgclose = (this.statshr.scrJrefDlgnew != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrBrlyLeg.scrJrefDlgnew != "") {
								srefDlg = "DlgBrlyLegNew";
								scrJrefDlg = dpcheng.StatShrBrlyLeg.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrBrlyLeg;
				}
				if (dpcheng.TagBrlyLeg) {
					Brly.unescapeBlock(dpcheng.TagBrlyLeg);
					this.tag = dpcheng.TagBrlyLeg;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyLegList.handleReply(obj);
					else this.$refs.PnlBrlyLegRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyLegData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyLegList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyLegRec.handleUpdate(obj);
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
