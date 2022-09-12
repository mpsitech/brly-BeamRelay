<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<div
				class="my-1"
			>
				<!-- IP divReu - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfDph"
				:label="tag.CptDph"
				:disabled="!statshr.TxfDphActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAl0"
				:label="tag.CptAl0"
				:disabled="!statshr.TxfAl0Active"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAl1"
				:label="tag.CptAl1"
				:disabled="!statshr.TxfAl1Active"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTh0"
				:label="tag.CptTh0"
				:disabled="!statshr.TxfTh0Active"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTh1"
				:label="tag.CptTh1"
				:disabled="!statshr.TxfTh1Active"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfPh0"
				:label="tag.CptPh0"
				:disabled="!statshr.TxfPh0Active"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfPh1"
				:label="tag.CptPh1"
				:disabled="!statshr.TxfPh1Active"
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
		name: 'PnlBrlySegDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlySegDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlySegDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlySegDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlySegDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlySegDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlySegDetail) this.contiac = dpcheng.ContIacBrlySegDetail;
				if (dpcheng.ContInfBrlySegDetail) this.continf = dpcheng.ContInfBrlySegDetail;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.StatAppBrlySegDetail) this.statapp = dpcheng.StatAppBrlySegDetail;
				if (dpcheng.StatShrBrlySegDetail) this.statshr = dpcheng.StatShrBrlySegDetail;
				if (dpcheng.TagBrlySegDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlySegDetail);
					this.tag = dpcheng.TagBrlySegDetail;
				}
				if (dpcheng.ContIacBrlySegDetail) {
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
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
				if (srefIxBrlyVDpch == "DpchEngBrlySegDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlySegDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupRet: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupRet: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
