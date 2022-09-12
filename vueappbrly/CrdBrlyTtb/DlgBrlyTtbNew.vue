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
		</v-card-title>
		<v-card-text>
			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupAli"
				:items="feedFDetPupAli"
				:label='tag.CptDetAli'
				v-on:change="handlePupChange('numFDetPupAli', contapp.fiFDetPupAli)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfTit"
				:label="tag.CptDetTit"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfSta"
				:label="tag.CptDetSta"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfSto"
				:label="tag.CptDetSto"
			/>

		</v-card-text>
		<v-divider/>
		<v-card-actions>
			<v-spacer/>
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButCncClick')"
			>
				{{tag.ButCnc}}
			</v-btn>
			&#160;
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButCreClick')"
			>
				{{tag.ButCre}}
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
		name: 'DlgBrlyTtbNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgBrlyTtbNew.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgBrlyTtbNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgBrlyTtbNewDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgBrlyTtbNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgBrlyTtbNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgBrlyTtbNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgBrlyTtbNew) this.contiac = dpcheng.ContIacDlgBrlyTtbNew;
				if (dpcheng.ContInfDlgBrlyTtbNew) this.continf = dpcheng.ContInfDlgBrlyTtbNew;
				if (dpcheng.FeedFDetPupAli) this.feedFDetPupAli = dpcheng.FeedFDetPupAli;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgBrlyTtbNew) this.statapp = dpcheng.StatAppDlgBrlyTtbNew;
				if (dpcheng.StatShrDlgBrlyTtbNew) this.statshr = dpcheng.StatShrDlgBrlyTtbNew;
				if (dpcheng.TagDlgBrlyTtbNew) {
					Brly.unescapeBlock(dpcheng.TagDlgBrlyTtbNew);
					this.tag = dpcheng.TagDlgBrlyTtbNew;
				}
				if (dpcheng.ContIacDlgBrlyTtbNew) {
					for (let i = 0; i < this.feedFDetPupAli.length; i++)
						if (this.feedFDetPupAli[i].num == this.contiac.numFDetPupAli) {
							this.contapp.fiFDetPupAli = this.feedFDetPupAli[i];
							break;
						}
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
				if (srefIxBrlyVDpch == "DpchEngDlgBrlyTtbNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngDlgBrlyTtbNewData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDetPupAli: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupAli: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
