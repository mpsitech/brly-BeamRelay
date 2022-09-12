<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFlt"
				:label="tag.CptFlt"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCor"
				:label="tag.CptCor"
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

			<v-select
				class="my-1"
				v-model="contapp.fiFPupMod"
				:items="feedFPupMod"
				:label='tag.CptMod'
				v-on:change="handlePupChange('numFPupMod', contapp.fiFPupMod)"
				:disabled="!statshr.PupModActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTtb"
				:label="tag.CptTtb"
			/>

			<div
				class="my-1"
			>
				<!-- IP divEty - INSERT -->
			</div>

		</v-card-text>
	</v-card>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyConDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyConDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyConDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyConDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyConDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyConDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyConDetail) this.contiac = dpcheng.ContIacBrlyConDetail;
				if (dpcheng.ContInfBrlyConDetail) this.continf = dpcheng.ContInfBrlyConDetail;
				if (dpcheng.FeedFLstEty) this.feedFLstEty = dpcheng.FeedFLstEty;
				if (dpcheng.FeedFPupMod) this.feedFPupMod = dpcheng.FeedFPupMod;
				if (dpcheng.StatAppBrlyConDetail) this.statapp = dpcheng.StatAppBrlyConDetail;
				if (dpcheng.StatShrBrlyConDetail) this.statshr = dpcheng.StatShrBrlyConDetail;
				if (dpcheng.TagBrlyConDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlyConDetail);
					this.tag = dpcheng.TagBrlyConDetail;
				}
				if (dpcheng.ContIacBrlyConDetail) {
					for (let i = 0; i < this.feedFPupMod.length; i++)
						if (this.feedFPupMod[i].num == this.contiac.numFPupMod) {
							this.contapp.fiFPupMod = this.feedFPupMod[i];
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
				if (srefIxBrlyVDpch == "DpchEngBrlyConDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyConDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstEty: null,

			feedFPupMod: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupMod: null,

				fisFLstEty: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
