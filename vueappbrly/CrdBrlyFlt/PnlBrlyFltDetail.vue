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

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTtb"
				:label="tag.CptTtb"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtLeg"
				:label="tag.CptLeg"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSta"
				:label="tag.CptSta"
				:disabled="!statshr.TxfStaActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSto"
				:label="tag.CptSto"
				:disabled="!statshr.TxfStoActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfXsa"
				:label="tag.CptXsa"
				:disabled="!statshr.TxfXsaActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfXso"
				:label="tag.CptXso"
				:disabled="!statshr.TxfXsoActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkCdn"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptCdn"
				:disabled="!statshr.ChkCdnActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkSdn"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptSdn"
				:disabled="!statshr.ChkSdnActive"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgFaf}}
			</h3>

			<v-text-field
				v-if="statshr.TxfFafFidAvail"
				class="my-1"
				v-model="contiac.TxfFafFid"
				:label="tag.CptFafFid"
				:disabled="!statshr.TxfFafFidActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafIdtAvail"
				class="my-1"
				v-model="contiac.TxfFafIdt"
				:label="tag.CptFafIdt"
				:disabled="!statshr.TxfFafIdtActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafActAvail"
				class="my-1"
				v-model="contiac.TxfFafAct"
				:label="tag.CptFafAct"
				:disabled="!statshr.TxfFafActActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafFetAvail"
				class="my-1"
				v-model="contiac.TxfFafFet"
				:label="tag.CptFafFet"
				:disabled="!statshr.TxfFafFetActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafFtiAvail"
				class="my-1"
				v-model="contiac.TxfFafFti"
				:label="tag.CptFafFti"
				:disabled="!statshr.TxfFafFtiActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafFdtAvail"
				class="my-1"
				v-model="contiac.TxfFafFdt"
				:label="tag.CptFafFdt"
				:disabled="!statshr.TxfFafFdtActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafFskAvail"
				class="my-1"
				v-model="contiac.TxfFafFsk"
				:label="tag.CptFafFsk"
				:disabled="!statshr.TxfFafFskActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafFsmAvail"
				class="my-1"
				v-model="contiac.TxfFafFsm"
				:label="tag.CptFafFsm"
				:disabled="!statshr.TxfFafFsmActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafFatAvail"
				class="my-1"
				v-model="contiac.TxfFafFat"
				:label="tag.CptFafFat"
				:disabled="!statshr.TxfFafFatActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafRteAvail"
				class="my-1"
				v-model="contiac.TxfFafRte"
				:label="tag.CptFafRte"
				:disabled="!statshr.TxfFafRteActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafAdtAvail"
				class="my-1"
				v-model="contiac.TxfFafAdt"
				:label="tag.CptFafAdt"
				:disabled="!statshr.TxfFafAdtActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafEatAvail"
				class="my-1"
				v-model="contiac.TxfFafEat"
				:label="tag.CptFafEat"
				:disabled="!statshr.TxfFafEatActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafAatAvail"
				class="my-1"
				v-model="contiac.TxfFafAat"
				:label="tag.CptFafAat"
				:disabled="!statshr.TxfFafAatActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafDvtAvail"
				class="my-1"
				v-model="contiac.TxfFafDvt"
				:label="tag.CptFafDvt"
				:disabled="!statshr.TxfFafDvtActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafOrgAvail"
				class="my-1"
				v-model="contiac.TxfFafOrg"
				:label="tag.CptFafOrg"
				:disabled="!statshr.TxfFafOrgActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafDstAvail"
				class="my-1"
				v-model="contiac.TxfFafDst"
				:label="tag.CptFafDst"
				:disabled="!statshr.TxfFafDstActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafOnmAvail"
				class="my-1"
				v-model="contiac.TxfFafOnm"
				:label="tag.CptFafOnm"
				:disabled="!statshr.TxfFafOnmActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafOctAvail"
				class="my-1"
				v-model="contiac.TxfFafOct"
				:label="tag.CptFafOct"
				:disabled="!statshr.TxfFafOctActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafDnmAvail"
				class="my-1"
				v-model="contiac.TxfFafDnm"
				:label="tag.CptFafDnm"
				:disabled="!statshr.TxfFafDnmActive"
			/>

			<v-text-field
				v-if="statshr.TxfFafDctAvail"
				class="my-1"
				v-model="contiac.TxfFafDct"
				:label="tag.CptFafDct"
				:disabled="!statshr.TxfFafDctActive"
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
		name: 'PnlBrlyFltDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyFltDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyFltDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyFltDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyFltDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyFltDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyFltDetail) this.contiac = dpcheng.ContIacBrlyFltDetail;
				if (dpcheng.ContInfBrlyFltDetail) this.continf = dpcheng.ContInfBrlyFltDetail;
				if (dpcheng.FeedFPupEqpEty) this.feedFPupEqpEty = dpcheng.FeedFPupEqpEty;
				if (dpcheng.StatAppBrlyFltDetail) this.statapp = dpcheng.StatAppBrlyFltDetail;
				if (dpcheng.StatShrBrlyFltDetail) this.statshr = dpcheng.StatShrBrlyFltDetail;
				if (dpcheng.TagBrlyFltDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlyFltDetail);
					this.tag = dpcheng.TagBrlyFltDetail;
				}
				if (dpcheng.ContIacBrlyFltDetail) {
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
				if (srefIxBrlyVDpch == "DpchEngBrlyFltDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyFltDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
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
