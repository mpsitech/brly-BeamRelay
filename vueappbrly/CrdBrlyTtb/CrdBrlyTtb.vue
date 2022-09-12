<template>
	<v-container v-if="initdone">
		<PnlBrlyTtbList
			v-on:request="handleRequest"
			ref="PnlBrlyTtbList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyTtbRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyTtbRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyTtbList from './PnlBrlyTtbList';
	import PnlBrlyTtbRec from './PnlBrlyTtbRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyTtb',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyTtbList,
			PnlBrlyTtbRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyTtb.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfBrlyTtb) this.continf = dpcheng.ContInfBrlyTtb;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyTtb) this.statapp = dpcheng.StatAppBrlyTtb;
				if (dpcheng.StatShrBrlyTtb) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrBrlyTtb.scrJrefDlgimpflt != "") || (dpcheng.StatShrBrlyTtb.scrJrefDlgnew != "") || (dpcheng.StatShrBrlyTtb.scrJrefDlgtrlorig != ""));
						dlgclose = ((this.statshr.scrJrefDlgimpflt != "") || (this.statshr.scrJrefDlgnew != "") || (this.statshr.scrJrefDlgtrlorig != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrBrlyTtb.scrJrefDlgimpflt != "") {
								srefDlg = "DlgBrlyTtbImpflt";
								scrJrefDlg = dpcheng.StatShrBrlyTtb.scrJrefDlgimpflt;
							} else if (dpcheng.StatShrBrlyTtb.scrJrefDlgnew != "") {
								srefDlg = "DlgBrlyTtbNew";
								scrJrefDlg = dpcheng.StatShrBrlyTtb.scrJrefDlgnew;
							} else if (dpcheng.StatShrBrlyTtb.scrJrefDlgtrlorig != "") {
								srefDlg = "DlgBrlyTtbTrlorig";
								scrJrefDlg = dpcheng.StatShrBrlyTtb.scrJrefDlgtrlorig;
							}
						}
					}
					this.statshr = dpcheng.StatShrBrlyTtb;
				}
				if (dpcheng.TagBrlyTtb) {
					Brly.unescapeBlock(dpcheng.TagBrlyTtb);
					this.tag = dpcheng.TagBrlyTtb;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyTtbList.handleReply(obj);
					else this.$refs.PnlBrlyTtbRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyTtbData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyTtbList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyTtbRec.handleUpdate(obj);
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
