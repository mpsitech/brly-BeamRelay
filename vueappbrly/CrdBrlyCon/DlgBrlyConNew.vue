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
							<v-text-field
								class="my-1"
								v-model="contiacdet.TxfFlt"
								:label="tagdet.CptFlt"
							/>

							<v-select
								class="my-1"
								v-model="contappdet.fiFPupMdl"
								:items="feedFDetPupMdl"
								:label='tagdet.CptMdl'
								v-on:change="handlePupChange('det', 'numFPupMdl', contappdet.fiFPupMdl)"
							>
								<template v-slot:selection="{item}">{{item.tit1}}</template>
								<template v-slot:item="{item}">{{item.tit1}}</template>
							</v-select>

							<v-select
								class="my-1"
								v-model="contappdet.fiFPupTtb"
								:items="feedFDetPupTtb"
								:label='tagdet.CptTtb'
								v-on:change="handlePupChange('det', 'numFPupTtb', contappdet.fiFPupTtb)"
							>
								<template v-slot:selection="{item}">{{item.tit1}}</template>
								<template v-slot:item="{item}">{{item.tit1}}</template>
							</v-select>

							<v-text-field
								class="my-1"
								v-model="contiacdet.TxfEty"
								:label="tagdet.CptEty"
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
								v-model="continfcal.TxtPrg"
								:label="tagcal.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('cal', 'ButRunClick')"
										:disabled="!statshrcal.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagcal.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('cal', 'ButStoClick')"
										:disabled="!statshrcal.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagcal.ButSto}}
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
		name: 'DlgBrlyConNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgBrlyConNew.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgBrlyConNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgBrlyConNewDo"]["srefIxVDo" + ditshort] = ctlsref;

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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgBrlyConNew"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgBrlyConNewDet"] = this.contiacdet;
				if (mask.indexOf("contiaccal") != -1) dpchapp["ContIacDlgBrlyConNewCal"] = this.contiaccal;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgBrlyConNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgBrlyConNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgBrlyConNew) this.contiac = dpcheng.ContIacDlgBrlyConNew;
				if (dpcheng.ContIacDlgBrlyConNewDet) this.contiacdet = dpcheng.ContIacDlgBrlyConNewDet;
				if (dpcheng.ContInfDlgBrlyConNew) this.continf = dpcheng.ContInfDlgBrlyConNew;
				if (dpcheng.ContInfDlgBrlyConNewCal) this.continfcal = dpcheng.ContInfDlgBrlyConNewCal;
				if (dpcheng.FeedFDetPupMdl) this.feedFDetPupMdl = dpcheng.FeedFDetPupMdl;
				if (dpcheng.FeedFDetPupTtb) this.feedFDetPupTtb = dpcheng.FeedFDetPupTtb;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgBrlyConNew) this.statapp = dpcheng.StatAppDlgBrlyConNew;
				if (dpcheng.StatShrDlgBrlyConNew) this.statshr = dpcheng.StatShrDlgBrlyConNew;
				if (dpcheng.StatShrDlgBrlyConNewCal) this.statshrcal = dpcheng.StatShrDlgBrlyConNewCal;
				if (dpcheng.StatShrDlgBrlyConNewDet) this.statshrdet = dpcheng.StatShrDlgBrlyConNewDet;
				if (dpcheng.TagDlgBrlyConNew) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyConNew);
					this.tag = dpcheng.TagDlgBrlyConNew;
				}
				if (dpcheng.TagDlgBrlyConNewCal) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyConNewCal);
					this.tagcal = dpcheng.TagDlgBrlyConNewCal;
				}
				if (dpcheng.TagDlgBrlyConNewDet) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyConNewDet);
					this.tagdet = dpcheng.TagDlgBrlyConNewDet;
				}
				if (dpcheng.ContIacDlgBrlyConNewDet) {
					for (let i = 0; i < this.feedFDetPupMdl.length; i++)
						if (this.feedFDetPupMdl[i].num == this.contiacdet.numFPupMdl) {
							this.contappdet.fiFPupMdl = this.feedFDetPupMdl[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupTtb.length; i++)
						if (this.feedFDetPupTtb[i].num == this.contiacdet.numFPupTtb) {
							this.contappdet.fiFPupTtb = this.feedFDetPupTtb[i];
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
				if (srefIxBrlyVDpch == "DpchEngDlgBrlyConNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngDlgBrlyConNewData") this.mergeDpchEngData(obj.dpcheng);
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

			continfcal: null,

			feedFDetPupMdl: null,

			feedFDetPupTtb: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrcal: null,

			statshrdet: null,

			tag: null,

			tagcal: null,

			tagdet: null,

			contappdet: {
				fiFPupMdl: null,

				fiFPupTtb: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
