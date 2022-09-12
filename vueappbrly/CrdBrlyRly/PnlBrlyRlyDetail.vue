<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
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
				readonly
				outlined
				v-model="continf.TxtCon"
				:label="tag.CptCon"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupDir"
				:items="feedFPupDir"
				:label='tag.CptDir'
				v-on:change="handlePupChange('numFPupDir', contapp.fiFPupDir)"
				:disabled="!statshr.PupDirActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkCtd"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptCtd"
				:disabled="!statshr.ChkCtdActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfNhp"
				:label="tag.CptNhp"
				:disabled="!statshr.TxfNhpActive"
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
		name: 'PnlBrlyRlyDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyRlyDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyRlyDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyRlyDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyRlyDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyRlyDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyRlyDetail) this.contiac = dpcheng.ContIacBrlyRlyDetail;
				if (dpcheng.ContInfBrlyRlyDetail) this.continf = dpcheng.ContInfBrlyRlyDetail;
				if (dpcheng.FeedFPupDir) this.feedFPupDir = dpcheng.FeedFPupDir;
				if (dpcheng.StatAppBrlyRlyDetail) this.statapp = dpcheng.StatAppBrlyRlyDetail;
				if (dpcheng.StatShrBrlyRlyDetail) this.statshr = dpcheng.StatShrBrlyRlyDetail;
				if (dpcheng.TagBrlyRlyDetail) {
					Brly.unescapeBlock(dpcheng.TagBrlyRlyDetail);
					this.tag = dpcheng.TagBrlyRlyDetail;
				}
				if (dpcheng.ContIacBrlyRlyDetail) {
					for (let i = 0; i < this.feedFPupDir.length; i++)
						if (this.feedFPupDir[i].num == this.contiac.numFPupDir) {
							this.contapp.fiFPupDir = this.feedFPupDir[i];
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
				if (srefIxBrlyVDpch == "DpchEngBrlyRlyDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyRlyDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupDir: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupDir: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
