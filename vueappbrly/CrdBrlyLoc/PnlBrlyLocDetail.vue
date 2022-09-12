<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSrf"
				:label="tag.CptSrf"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfIca"
				:label="tag.CptIca"
				:disabled="!statshr.TxfIcaActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
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

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtReg"
				:label="tag.CptReg"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAlt"
				:label="tag.CptAlt"
				:disabled="!statshr.TxfAltActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfThe"
				:label="tag.CptThe"
				:disabled="!statshr.TxfTheActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfPhi"
				:label="tag.CptPhi"
				:disabled="!statshr.TxfPhiActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTz"
				:label="tag.CptTz"
				:disabled="!statshr.TxfTzActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAph"
				:label="tag.CptAph"
				:disabled="!statshr.TxfAphActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkCdn"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptCdn"
				:disabled="!statshr.ChkCdnActive"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgEqp}}
			</h3>

			<v-text-field
				v-if="statshr.TxtEqpOprAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtEqpOpr"
				:label="tag.CptEqpOpr"
			/>

			<v-text-field
				v-if="statshr.TxtEqpPtyAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtEqpPty"
				:label="tag.CptEqpPty"
			/>

			<div
				v-if="statshr.PupEqpEtyAvail"
				class="my-1"
			>
				<!-- IP divEqpEty - INSERT -->
			</div>

			<v-checkbox
				v-if="statshr.ChkEqpFibAvail"
				class="my-1"
				v-model="contiac.ChkEqpFib"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptEqpFib"
				:disabled="!statshr.ChkEqpFibActive"
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
		name: 'PnlBrlyLocDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyLocDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyLocDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyLocDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyLocDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyLocDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyLocDetail) this.contiac = dpcheng.ContIacBrlyLocDetail;
				if (dpcheng.ContInfBrlyLocDetail) this.continf = dpcheng.ContInfBrlyLocDetail;
				if (dpcheng.FeedFPupEqpEty) this.feedFPupEqpEty = dpcheng.FeedFPupEqpEty;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppBrlyLocDetail) this.statapp = dpcheng.StatAppBrlyLocDetail;
				if (dpcheng.StatShrBrlyLocDetail) this.statshr = dpcheng.StatShrBrlyLocDetail;
				if (dpcheng.TagBrlyLocDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlyLocDetail);
					this.tag = dpcheng.TagBrlyLocDetail;
				}
				if (dpcheng.ContIacBrlyLocDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupEqpEty.length; i++)
						if (this.feedFPupEqpEty[i].num == this.contiac.numFPupEqpEty) {
							this.contapp.fiFPupEqpEty = this.feedFPupEqpEty[i];
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
				if (srefIxBrlyVDpch == "DpchEngBrlyLocDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyLocDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupEqpEty: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupEqpEty: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
