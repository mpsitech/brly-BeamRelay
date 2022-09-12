<template>
	<v-card v-if="initdone" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{tag.Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end"/>
			</v-row>
			<v-tabs
				v-model="numFDse"
				align-with-title
			>
				<v-tabs-slider></v-tabs-slider>
				<v-tab v-for="{num, tit1} in feedFDse" :key="num">{{tit1}}</v-tab>
			</v-tabs>
		</v-card-title>
		<v-card-text>
			<v-tabs-items v-model="numFDse">
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-select
								class="my-1"
								v-model="contappdet.fiFPupTyp"
								:items="feedFDetPupTyp"
								:label='tagdet.CptTyp'
								v-on:change="handlePupChange('det', 'numFPupTyp', contappdet.fiFPupTyp)"
							>
								<template v-slot:selection="{item}">{{item.tit1}}</template>
								<template v-slot:item="{item}">{{item.tit1}}</template>
							</v-select>

							<v-text-field
								class="my-1"
								v-model="contiacdet.TxfBgn"
								:label="tagdet.CptBgn"
							/>

							<v-text-field
								class="my-1"
								v-model="contiacdet.TxfEnd"
								:label="tagdet.CptEnd"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('det', 'ButCreClick')"
										:disabled="!statshrdet.ButCreActive"
										class="my-1"
										color="primary"
									>
										{{tagdet.ButCre}}
									</v-btn>
								</v-col>
							</v-row>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-text-field
								class="my-1"
								readonly
								outlined
								v-model="continfinc.TxtPrg"
								:label="taginc.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('inc', 'ButRunClick')"
										:disabled="!statshrinc.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{taginc.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('inc', 'ButStoClick')"
										:disabled="!statshrinc.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{taginc.ButSto}}
									</v-btn>
								</v-col>
							</v-row>

						</v-card-text>
					</v-card>
				</v-tab-item>
			</v-tabs-items>
		</v-card-text>
		<v-divider/>
		<v-card-actions>
			<v-spacer/>
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButDneClick')"
			>
				{{tag.ButDne}}
			</v-btn>
		</v-card-actions>
	</v-card>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'DlgBrlyLegNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgBrlyLegNew.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(ditshort, ctlsref) {
				var dpchapp = {
					"DpchAppDlgBrlyLegNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgBrlyLegNewDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgBrlyLegNew"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgBrlyLegNewDet"] = this.contiacdet;
				if (mask.indexOf("contiacinc") != -1) dpchapp["ContIacDlgBrlyLegNewInc"] = this.contiacinc;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgBrlyLegNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgBrlyLegNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgBrlyLegNew) this.contiac = dpcheng.ContIacDlgBrlyLegNew;
				if (dpcheng.ContIacDlgBrlyLegNewDet) this.contiacdet = dpcheng.ContIacDlgBrlyLegNewDet;
				if (dpcheng.ContInfDlgBrlyLegNew) this.continf = dpcheng.ContInfDlgBrlyLegNew;
				if (dpcheng.ContInfDlgBrlyLegNewInc) this.continfinc = dpcheng.ContInfDlgBrlyLegNewInc;
				if (dpcheng.FeedFDetPupTyp) this.feedFDetPupTyp = dpcheng.FeedFDetPupTyp;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgBrlyLegNew) this.statapp = dpcheng.StatAppDlgBrlyLegNew;
				if (dpcheng.StatShrDlgBrlyLegNew) this.statshr = dpcheng.StatShrDlgBrlyLegNew;
				if (dpcheng.StatShrDlgBrlyLegNewDet) this.statshrdet = dpcheng.StatShrDlgBrlyLegNewDet;
				if (dpcheng.StatShrDlgBrlyLegNewInc) this.statshrinc = dpcheng.StatShrDlgBrlyLegNewInc;
				if (dpcheng.TagDlgBrlyLegNew) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyLegNew);
					this.tag = dpcheng.TagDlgBrlyLegNew;
				}
				if (dpcheng.TagDlgBrlyLegNewDet) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyLegNewDet);
					this.tagdet = dpcheng.TagDlgBrlyLegNewDet;
				}
				if (dpcheng.TagDlgBrlyLegNewInc) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyLegNewInc);
					this.taginc = dpcheng.TagDlgBrlyLegNewInc;
				}
				if (dpcheng.ContIacDlgBrlyLegNewDet) {
					for (let i = 0; i < this.feedFDetPupTyp.length; i++)
						if (this.feedFDetPupTyp[i].num == this.contiacdet.numFPupTyp) {
							this.contappdet.fiFPupTyp = this.feedFDetPupTyp[i];
							break;
						}
				}
				/*
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxBrlyVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxBrlyVDpch, dpcheng) {
				if (srefIxBrlyVDpch == "DpchEngDlgBrlyLegNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngDlgBrlyLegNewData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {

			numFDse: {
				get() {
					return this.contiac.numFDse - 1;
				},
				set(sel) {
					if (sel == null) this.contiac.numFDse = 1;
					else this.contiac.numFDse = sel + 1;

					return sel;
				}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			contiacdet: null,

			continf: null,

			continfinc: null,

			feedFDetPupTyp: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrdet: null,

			statshrinc: null,

			tag: null,

			tagdet: null,

			taginc: null,

			contappdet: {
				fiFPupTyp: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
