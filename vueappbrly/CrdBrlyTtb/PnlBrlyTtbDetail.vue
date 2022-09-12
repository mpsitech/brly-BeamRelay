<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFil"
				:label="tag.CptFil"
			/>

			<div
				class="my-1"
			>
				<!-- IP divAli - INSERT -->
			</div>

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

		</v-card-text>
	</v-card>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyTtbDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyTtbDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyTtbDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyTtbDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyTtbDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyTtbDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyTtbDetail) this.contiac = dpcheng.ContIacBrlyTtbDetail;
				if (dpcheng.ContInfBrlyTtbDetail) this.continf = dpcheng.ContInfBrlyTtbDetail;
				if (dpcheng.FeedFPupAli) this.feedFPupAli = dpcheng.FeedFPupAli;
				if (dpcheng.StatAppBrlyTtbDetail) this.statapp = dpcheng.StatAppBrlyTtbDetail;
				if (dpcheng.StatShrBrlyTtbDetail) this.statshr = dpcheng.StatShrBrlyTtbDetail;
				if (dpcheng.TagBrlyTtbDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlyTtbDetail);
					this.tag = dpcheng.TagBrlyTtbDetail;
				}
				if (dpcheng.ContIacBrlyTtbDetail) {
					for (let i = 0; i < this.feedFPupAli.length; i++)
						if (this.feedFPupAli[i].num == this.contiac.numFPupAli) {
							this.contapp.fiFPupAli = this.feedFPupAli[i];
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
				if (srefIxBrlyVDpch == "DpchEngBrlyTtbDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyTtbDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupAli: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupAli: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
