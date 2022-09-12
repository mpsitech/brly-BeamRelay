<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end">
					&#160;
					<v-btn
						v-if="statapp.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClipboardClick()"
						:value="1"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButCrdopenClick('ButViewClick')"
						:value="1"
						:disabled="!statshr.ButViewActive"
					>
						<v-icon color="white">mdi-book-arrow-up</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statapp.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButAddClick')"
						:value="1"
					>
						<v-icon color="white">mdi-add</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButSubClick')"
						:value="1"
						:disabled="!statshr.ButSubActive"
					>
						<v-icon color="white">mdi-sub</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statapp.srefIxBrlyVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxBrlyVExpstate='regd'"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxBrlyVExpstate='mind'"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statapp.srefIxBrlyVExpstate=='regd'"
		>
			<v-data-table
				:headers="headers"
				:items="contapp.rows"
				:items-per-page="10"
				item-key="jnum"
				single-select
				show-select
				class="elevation-1 my-3"
				v-on:item-selected="handleSelect"
			/>

			<v-row>
				<v-col align="end">
					<v-tooltip left>
						<template v-slot:activator="{on,attrs}">
							<v-btn
								fab
								small
								light
								v-bind="attrs"
								v-on="on"
								:color="fiFCsiQst.sref == 'ong' ? 'orange' : fiFCsiQst.sref == 'red' ? 'red' : fiFCsiQst.sref == 'yel' ? 'yellow' : fiFCsiQst.sref == 'grn' ? 'green' : 'primary'"
								v-on:click="handleButClick('ButRefreshClick')"
							>
								<v-icon color="white">mdi-refresh</v-icon>
							</v-btn>
						</template>
						{{fiFCsiQst.tit1}}
					</v-tooltip>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyConMNFlight',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyConMNFlight.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppBrlyInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppBrlyConMNFlightDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButClipboardClick: function() {
				/*
				*/
				Brly.copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag,
							["Mref","Sta","Sto","Lp0","Lp1"],
							["mref","sta","sto","lp0","lp1"]);
				/*
				*/
			},

				handleButCrdopenClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppBrlyConMNFlightDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoCrdopenReply"});
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppBrlyConMNFlightData": {
						"scrJref": this.scrJref,
						"StgIacQryBrlyConMNFlight": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyConMNFlight"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyConMNFlightData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyConMNFlightData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContInfBrlyConMNFlight) this.continf = dpcheng.ContInfBrlyConMNFlight;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.StatAppBrlyConMNFlight) this.statapp = dpcheng.StatAppBrlyConMNFlight;
				if (dpcheng.StatShrBrlyConMNFlight) this.statshr = dpcheng.StatShrBrlyConMNFlight;
				if (dpcheng.StgIacBrlyConMNFlight) this.stgiac = dpcheng.StgIacBrlyConMNFlight;
				if (dpcheng.TagBrlyConMNFlight) {
					Brly.unescapeBlock(dpcheng.TagBrlyConMNFlight);
					this.tag = dpcheng.TagBrlyConMNFlight;
				}
				if (dpcheng.ListBrlyQConMNFlight) this.rst = dpcheng.ListBrlyQConMNFlight;
				if (dpcheng.StatAppQryBrlyConMNFlight) this.statappqry = dpcheng.StatAppQryBrlyConMNFlight;
				if (dpcheng.StatShrQryBrlyConMNFlight) this.statshrqry = dpcheng.StatShrQryBrlyConMNFlight;
				if (dpcheng.StgIacQryBrlyConMNFlight) this.stgiacqry = dpcheng.StgIacQryBrlyConMNFlight;
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagBrlyConMNFlight) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoMref", text: this.tag.TcoMref}, {value: "TcoSta", text: this.tag.TcoSta}, {value: "TcoSto", text: this.tag.TcoSto}, {value: "TcoLp0", text: this.tag.TcoLp0}, {value: "TcoLp1", text: this.tag.TcoLp1});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListBrlyQConMNFlight) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoMref: rec["mref"], TcoSta: rec["sta"], TcoSto: rec["sto"], TcoLp0: rec["lp0"], TcoLp1: rec["lp1"]})
						/*
						*/

					}

					this.contapp.rows = rows;
				}
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxBrlyVDpch, obj.dpcheng);
				else if (obj.then == "handleDpchAppDoCrdopenReply") this.handleDpchAppDoCrdopenReply(obj.srefIxBrlyVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxBrlyVDpch, dpcheng) {
				if (srefIxBrlyVDpch == "DpchEngBrlyConMNFlightData") this.mergeDpchEngData(dpcheng);
			},

			handleDpchAppDoCrdopenReply: function(srefIxBrlyVDpch, dpcheng) {
				if (srefIxBrlyVDpch == "DpchEngBrlyConfirm")
					if (dpcheng.accepted)
						this.$emit("crdopen", {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false});
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyConMNFlightData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			/*
			*/
			Cpt: function() {
				if (this.statapp.srefIxBrlyVExpstate == "mind") return(this.tag.Cpt + " (" + this.statshrqry.ntot + ")");
				return this.tag.Cpt;
			},
			/*
			*/

			headers: function() {
				return this.contapp.tcos.filter(x => x.value != "jnum")
			},

			fiFCsiQst: function() {
				if (this.feedFCsiQst && this.continf)
					for (var i = 0; i < this.feedFCsiQst.length; i++)
						if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return {sref: "gry", tit1: "invalid"}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFCsiQst: null,

			statapp: null,

			statshr: null,

			stgiac: null,

			tag: null,

			rst: null,

			statappqry: null,

			statshrqry: null,

			stgiacqry: null,

			contapp: {
				tcos: [],
				rows: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
