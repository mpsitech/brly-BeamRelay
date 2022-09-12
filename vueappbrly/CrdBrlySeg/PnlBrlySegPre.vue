<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statapp.srefIxBrlyVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxBrlyVExpstate='regd'"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxBrlyVExpstate='mind'"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statapp.srefIxBrlyVExpstate=='regd'"
		>
			<v-slider
				class="my-1"
				v-model="contiac.SldTme"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptTme"
				:min="statshr.SldTmeMin"
				:max="statshr.SldTmeMax"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldTme"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

			<v-slider
				class="my-1"
				v-model="contiac.SldPhi"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptPhi"
				:min="statshr.SldPhiMin"
				:max="statshr.SldPhiMax"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldPhi"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

		</v-card-text>
	</v-card>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlySegPre',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlySegPre.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlySegPreDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlySegPre"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlySegPreData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlySegPreData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlySegPre) this.contiac = dpcheng.ContIacBrlySegPre;
				if (dpcheng.StatAppBrlySegPre) this.statapp = dpcheng.StatAppBrlySegPre;
				if (dpcheng.StatShrBrlySegPre) this.statshr = dpcheng.StatShrBrlySegPre;
				if (dpcheng.TagBrlySegPre) {
					Brly.unescapeBlock(dpcheng.TagBrlySegPre);
					this.tag = dpcheng.TagBrlySegPre;
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
				if (srefIxBrlyVDpch == "DpchEngBrlySegPreData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlySegPreData") this.mergeDpchEngData(obj.dpcheng);
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

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
