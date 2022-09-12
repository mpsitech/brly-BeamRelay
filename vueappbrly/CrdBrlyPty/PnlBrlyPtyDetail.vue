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
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
			/>

			<v-divider/>

			<div
				class="my-1"
			>
				<!-- IP divEty - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCap"
				:label="tag.CptCap"
				:disabled="!statshr.TxfCapActive"
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
		name: 'PnlBrlyPtyDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyPtyDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyPtyDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyPtyDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyPtyDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyPtyDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyPtyDetail) this.contiac = dpcheng.ContIacBrlyPtyDetail;
				if (dpcheng.ContInfBrlyPtyDetail) this.continf = dpcheng.ContInfBrlyPtyDetail;
				if (dpcheng.FeedFPupEty) this.feedFPupEty = dpcheng.FeedFPupEty;
				if (dpcheng.StatAppBrlyPtyDetail) this.statapp = dpcheng.StatAppBrlyPtyDetail;
				if (dpcheng.StatShrBrlyPtyDetail) this.statshr = dpcheng.StatShrBrlyPtyDetail;
				if (dpcheng.TagBrlyPtyDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlyPtyDetail);
					this.tag = dpcheng.TagBrlyPtyDetail;
				}
				if (dpcheng.ContIacBrlyPtyDetail) {
					for (let i = 0; i < this.feedFPupEty.length; i++)
						if (this.feedFPupEty[i].num == this.contiac.numFPupEty) {
							this.contapp.fiFPupEty = this.feedFPupEty[i];
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
				if (srefIxBrlyVDpch == "DpchEngBrlyPtyDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyPtyDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupEty: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupEty: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
