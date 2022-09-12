<template>
	<v-container v-if="initdone">
		<PnlBrlyConList
			v-on:request="handleRequest"
			ref="PnlBrlyConList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyConRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyConRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyConList from './PnlBrlyConList';
	import PnlBrlyConRec from './PnlBrlyConRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyCon',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyConList,
			PnlBrlyConRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyCon.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfBrlyCon) this.continf = dpcheng.ContInfBrlyCon;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyCon) this.statapp = dpcheng.StatAppBrlyCon;
				if (dpcheng.StatShrBrlyCon) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrBrlyCon.scrJrefDlgnew != "");
						dlgclose = (this.statshr.scrJrefDlgnew != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrBrlyCon.scrJrefDlgnew != "") {
								srefDlg = "DlgBrlyConNew";
								scrJrefDlg = dpcheng.StatShrBrlyCon.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrBrlyCon;
				}
				if (dpcheng.TagBrlyCon) {
					Brly.unescapeBlock(dpcheng.TagBrlyCon);
					this.tag = dpcheng.TagBrlyCon;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyConList.handleReply(obj);
					else this.$refs.PnlBrlyConRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyConData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyConList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyConRec.handleUpdate(obj);
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
