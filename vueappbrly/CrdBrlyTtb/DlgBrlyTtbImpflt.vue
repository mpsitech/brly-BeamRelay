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
							<v-file-input
								outlined
								show-size
								:label="tagifi.Cpt"
								v-model="contappifi.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('ifi')"
								:disabled="contappifi.file == null"
								color="primary"
							>
								{{tagifi.Uld}}
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
								v-model="continfimp.TxtPrg"
								:label="tagimp.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('imp', 'ButRunClick')"
										:disabled="!statshrimp.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagimp.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('imp', 'ButStoClick')"
										:disabled="!statshrimp.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagimp.ButSto}}
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
								v-model="continfppr.TxtPrg"
								:label="tagppr.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('ppr', 'ButRunClick')"
										:disabled="!statshrppr.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagppr.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('ppr', 'ButStoClick')"
										:disabled="!statshrppr.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagppr.ButSto}}
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
								:disabled="!statshrlfi.DldActive"
								class="my-1"
								color="primary"
							>
								{{taglfi.Dld}}
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
		name: 'DlgBrlyTtbImpflt',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgBrlyTtbImpflt.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgBrlyTtbImpfltDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgBrlyTtbImpfltDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgBrlyTtbImpflt"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacifi") != -1) dpchapp["ContIacDlgBrlyTtbImpfltIfi"] = this.contiacifi;
				if (mask.indexOf("contiacimp") != -1) dpchapp["ContIacDlgBrlyTtbImpfltImp"] = this.contiacimp;
				if (mask.indexOf("contiacppr") != -1) dpchapp["ContIacDlgBrlyTtbImpfltPpr"] = this.contiacppr;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgBrlyTtbImpfltLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgBrlyTtbImpfltData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgBrlyTtbImpfltData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgBrlyTtbImpflt) this.contiac = dpcheng.ContIacDlgBrlyTtbImpflt;
				if (dpcheng.ContInfDlgBrlyTtbImpflt) this.continf = dpcheng.ContInfDlgBrlyTtbImpflt;
				if (dpcheng.ContInfDlgBrlyTtbImpfltImp) this.continfimp = dpcheng.ContInfDlgBrlyTtbImpfltImp;
				if (dpcheng.ContInfDlgBrlyTtbImpfltLfi) this.continflfi = dpcheng.ContInfDlgBrlyTtbImpfltLfi;
				if (dpcheng.ContInfDlgBrlyTtbImpfltPpr) this.continfppr = dpcheng.ContInfDlgBrlyTtbImpfltPpr;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgBrlyTtbImpflt) this.statapp = dpcheng.StatAppDlgBrlyTtbImpflt;
				if (dpcheng.StatShrDlgBrlyTtbImpflt) this.statshr = dpcheng.StatShrDlgBrlyTtbImpflt;
				if (dpcheng.StatShrDlgBrlyTtbImpfltIfi) this.statshrifi = dpcheng.StatShrDlgBrlyTtbImpfltIfi;
				if (dpcheng.StatShrDlgBrlyTtbImpfltImp) this.statshrimp = dpcheng.StatShrDlgBrlyTtbImpfltImp;
				if (dpcheng.StatShrDlgBrlyTtbImpfltLfi) this.statshrlfi = dpcheng.StatShrDlgBrlyTtbImpfltLfi;
				if (dpcheng.StatShrDlgBrlyTtbImpfltPpr) this.statshrppr = dpcheng.StatShrDlgBrlyTtbImpfltPpr;
				if (dpcheng.TagDlgBrlyTtbImpflt) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbImpflt);
					this.tag = dpcheng.TagDlgBrlyTtbImpflt;
				}
				if (dpcheng.TagDlgBrlyTtbImpfltIfi) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbImpfltIfi);
					this.tagifi = dpcheng.TagDlgBrlyTtbImpfltIfi;
				}
				if (dpcheng.TagDlgBrlyTtbImpfltImp) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbImpfltImp);
					this.tagimp = dpcheng.TagDlgBrlyTtbImpfltImp;
				}
				if (dpcheng.TagDlgBrlyTtbImpfltLfi) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbImpfltLfi);
					this.taglfi = dpcheng.TagDlgBrlyTtbImpfltLfi;
				}
				if (dpcheng.TagDlgBrlyTtbImpfltPpr) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbImpfltPpr);
					this.tagppr = dpcheng.TagDlgBrlyTtbImpfltPpr;
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
				if (srefIxBrlyVDpch == "DpchEngDlgBrlyTtbImpfltData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngDlgBrlyTtbImpfltData") this.mergeDpchEngData(obj.dpcheng);
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

			continf: null,

			continfimp: null,

			continflfi: null,

			continfppr: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrifi: null,

			statshrimp: null,

			statshrlfi: null,

			statshrppr: null,

			tag: null,

			tagifi: null,

			tagimp: null,

			taglfi: null,

			tagppr: null,

			contappifi: {
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
