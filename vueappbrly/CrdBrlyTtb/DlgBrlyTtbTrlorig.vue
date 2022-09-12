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
								v-model="contappdet.fiFPupSrc"
								:items="feedFDetPupSrc"
								:label='tagdet.CptSrc'
								v-on:change="handlePupChange('det', 'numFPupSrc', contappdet.fiFPupSrc)"
							>
								<template v-slot:selection="{item}">{{item.tit1}}</template>
								<template v-slot:item="{item}">{{item.tit1}}</template>
							</v-select>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-file-input
								outlined
								show-size
								:label="tagrfi.Cpt"
								v-model="contapprfi.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('rfi')"
								:disabled="contapprfi.file == null"
								color="primary"
							>
								{{tagrfi.Uld}}
							</v-btn>
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
								v-model="continftrl.TxtPrg"
								:label="tagtrl.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('trl', 'ButRunClick')"
										:disabled="!statshrtrl.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagtrl.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('trl', 'ButStoClick')"
										:disabled="!statshrtrl.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagtrl.ButSto}}
									</v-btn>
								</v-col>
							</v-row>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-btn
								download
								:href="hrefDld"
								:disabled="!statshrtfi.DldActive"
								class="my-1"
								color="primary"
							>
								{{tagtfi.Dld}}
							</v-btn>
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
		name: 'DlgBrlyTtbTrlorig',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgBrlyTtbTrlorig.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgBrlyTtbTrlorigDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgBrlyTtbTrlorigDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			handlePupChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgBrlyTtbTrlorig"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgBrlyTtbTrlorigDet"] = this.contiacdet;
				if (mask.indexOf("contiacrfi") != -1) dpchapp["ContIacDlgBrlyTtbTrlorigRfi"] = this.contiacrfi;
				if (mask.indexOf("contiactrl") != -1) dpchapp["ContIacDlgBrlyTtbTrlorigTrl"] = this.contiactrl;
				if (mask.indexOf("contiactfi") != -1) dpchapp["ContIacDlgBrlyTtbTrlorigTfi"] = this.contiactfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgBrlyTtbTrlorigData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgBrlyTtbTrlorigData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgBrlyTtbTrlorig) this.contiac = dpcheng.ContIacDlgBrlyTtbTrlorig;
				if (dpcheng.ContIacDlgBrlyTtbTrlorigDet) this.contiacdet = dpcheng.ContIacDlgBrlyTtbTrlorigDet;
				if (dpcheng.ContInfDlgBrlyTtbTrlorig) this.continf = dpcheng.ContInfDlgBrlyTtbTrlorig;
				if (dpcheng.ContInfDlgBrlyTtbTrlorigTfi) this.continftfi = dpcheng.ContInfDlgBrlyTtbTrlorigTfi;
				if (dpcheng.ContInfDlgBrlyTtbTrlorigTrl) this.continftrl = dpcheng.ContInfDlgBrlyTtbTrlorigTrl;
				if (dpcheng.FeedFDetPupSrc) this.feedFDetPupSrc = dpcheng.FeedFDetPupSrc;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgBrlyTtbTrlorig) this.statapp = dpcheng.StatAppDlgBrlyTtbTrlorig;
				if (dpcheng.StatShrDlgBrlyTtbTrlorig) this.statshr = dpcheng.StatShrDlgBrlyTtbTrlorig;
				if (dpcheng.StatShrDlgBrlyTtbTrlorigRfi) this.statshrrfi = dpcheng.StatShrDlgBrlyTtbTrlorigRfi;
				if (dpcheng.StatShrDlgBrlyTtbTrlorigTfi) this.statshrtfi = dpcheng.StatShrDlgBrlyTtbTrlorigTfi;
				if (dpcheng.StatShrDlgBrlyTtbTrlorigTrl) this.statshrtrl = dpcheng.StatShrDlgBrlyTtbTrlorigTrl;
				if (dpcheng.TagDlgBrlyTtbTrlorig) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbTrlorig);
					this.tag = dpcheng.TagDlgBrlyTtbTrlorig;
				}
				if (dpcheng.TagDlgBrlyTtbTrlorigDet) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbTrlorigDet);
					this.tagdet = dpcheng.TagDlgBrlyTtbTrlorigDet;
				}
				if (dpcheng.TagDlgBrlyTtbTrlorigRfi) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbTrlorigRfi);
					this.tagrfi = dpcheng.TagDlgBrlyTtbTrlorigRfi;
				}
				if (dpcheng.TagDlgBrlyTtbTrlorigTfi) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbTrlorigTfi);
					this.tagtfi = dpcheng.TagDlgBrlyTtbTrlorigTfi;
				}
				if (dpcheng.TagDlgBrlyTtbTrlorigTrl) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbTrlorigTrl);
					this.tagtrl = dpcheng.TagDlgBrlyTtbTrlorigTrl;
				}
				if (dpcheng.ContIacDlgBrlyTtbTrlorigDet) {
					for (let i = 0; i < this.feedFDetPupSrc.length; i++)
						if (this.feedFDetPupSrc[i].num == this.contiacdet.numFPupSrc) {
							this.contappdet.fiFPupSrc = this.feedFDetPupSrc[i];
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
				if (srefIxBrlyVDpch == "DpchEngDlgBrlyTtbTrlorigData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngDlgBrlyTtbTrlorigData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			hrefDld: function() {
				return window.location.protocol + '//' + Brly.hostname() + ':' + Brly.appsrvport() + '/download/' + this.scrJref;
			},

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

			continftfi: null,

			continftrl: null,

			feedFDetPupSrc: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrrfi: null,

			statshrtfi: null,

			statshrtrl: null,

			tag: null,

			tagdet: null,

			tagrfi: null,

			tagtfi: null,

			tagtrl: null,

			contappdet: {
				fiFPupSrc: null,

			},

			contapprfi: {
				file: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
