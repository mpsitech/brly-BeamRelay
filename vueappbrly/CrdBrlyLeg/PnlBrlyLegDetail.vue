<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtBlo"
				:label="tag.CptBlo"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtElo"
				:label="tag.CptElo"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupTyp"
				:items="feedFPupTyp"
				:label='tag.CptTyp'
				v-on:change="handlePupChange('numFPupTyp', contapp.fiFPupTyp)"
				:disabled="!statshr.PupTypActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-1"
			>
				<!-- IP divClu - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAlt"
				:label="tag.CptAlt"
				:disabled="!statshr.TxfAltActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfDph"
				:label="tag.CptDph"
				:disabled="!statshr.TxfDphActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAph"
				:label="tag.CptAph"
				:disabled="!statshr.TxfAphActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfXal"
				:label="tag.CptXal"
				:disabled="!statshr.TxfXalActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfXp0"
				:label="tag.CptXp0"
				:disabled="!statshr.TxfXp0Active"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfXp1"
				:label="tag.CptXp1"
				:disabled="!statshr.TxfXp1Active"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfXap"
				:label="tag.CptXap"
				:disabled="!statshr.TxfXapActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkCdn"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptCdn"
				:disabled="!statshr.ChkCdnActive"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyLegDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyLegDetail.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppBrlyLegDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyLegDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyLegDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyLegDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyLegDetail) this.contiac = dpcheng.ContIacBrlyLegDetail;
				if (dpcheng.ContInfBrlyLegDetail) this.continf = dpcheng.ContInfBrlyLegDetail;
				if (dpcheng.FeedFLstClu) this.feedFLstClu = dpcheng.FeedFLstClu;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppBrlyLegDetail) this.statapp = dpcheng.StatAppBrlyLegDetail;
				if (dpcheng.StatShrBrlyLegDetail) this.statshr = dpcheng.StatShrBrlyLegDetail;
				if (dpcheng.TagBrlyLegDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlyLegDetail);
					this.tag = dpcheng.TagBrlyLegDetail;
				}
				if (dpcheng.ContIacBrlyLegDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFLstClu.length; i++)
						if (this.feedFLstClu[i].num == this.contiac.numFLstClu) {
							this.contapp.fiFLstClu = this.feedFLstClu[i];
							break;
						}
				}
				/*
				<!-- IP mergeDpchEngData - END -->
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
				if (srefIxBrlyVDpch == "DpchEngBrlyLegDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyLegDetailData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFLstClu: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFLstClu: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
