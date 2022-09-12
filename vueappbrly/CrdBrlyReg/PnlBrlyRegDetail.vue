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

			<div
				class="my-1"
			>
				<!-- IP divJti - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTit"
				:label="tag.CptTit"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSup"
				:label="tag.CptSup"
			/>

			<div
				class="my-1"
			>
				<!-- IP divJ - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupDst"
				:items="feedFPupDst"
				:label='tag.CptDst'
				v-on:change="handlePupChange('numFPupDst', contapp.fiFPupDst)"
				:disabled="!statshr.PupDstActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTof"
				:label="tag.CptTof"
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
		name: 'PnlBrlyRegDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyRegDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyRegDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyRegDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyRegDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyRegDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyRegDetail) this.contiac = dpcheng.ContIacBrlyRegDetail;
				if (dpcheng.ContInfBrlyRegDetail) this.continf = dpcheng.ContInfBrlyRegDetail;
				if (dpcheng.FeedFPupDst) this.feedFPupDst = dpcheng.FeedFPupDst;
				if (dpcheng.FeedFPupJ) this.feedFPupJ = dpcheng.FeedFPupJ;
				if (dpcheng.FeedFPupJti) this.feedFPupJti = dpcheng.FeedFPupJti;
				if (dpcheng.StatAppBrlyRegDetail) this.statapp = dpcheng.StatAppBrlyRegDetail;
				if (dpcheng.StatShrBrlyRegDetail) this.statshr = dpcheng.StatShrBrlyRegDetail;
				if (dpcheng.TagBrlyRegDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlyRegDetail);
					this.tag = dpcheng.TagBrlyRegDetail;
				}
				if (dpcheng.ContIacBrlyRegDetail) {
					for (let i = 0; i < this.feedFPupJti.length; i++)
						if (this.feedFPupJti[i].num == this.contiac.numFPupJti) {
							this.contapp.fiFPupJti = this.feedFPupJti[i];
							break;
						}
					for (let i = 0; i < this.feedFPupJ.length; i++)
						if (this.feedFPupJ[i].num == this.contiac.numFPupJ) {
							this.contapp.fiFPupJ = this.feedFPupJ[i];
							break;
						}
					for (let i = 0; i < this.feedFPupDst.length; i++)
						if (this.feedFPupDst[i].num == this.contiac.numFPupDst) {
							this.contapp.fiFPupDst = this.feedFPupDst[i];
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
				if (srefIxBrlyVDpch == "DpchEngBrlyRegDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyRegDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupDst: null,

			feedFPupJ: null,

			feedFPupJti: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJti: null,

				fiFPupJ: null,

				fiFPupDst: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
