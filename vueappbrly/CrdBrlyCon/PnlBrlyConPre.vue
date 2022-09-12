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
		name: 'PnlBrlyConPre',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyConPre.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyConPreDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyConPre"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyConPreData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyConPreData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyConPre) this.contiac = dpcheng.ContIacBrlyConPre;
				if (dpcheng.StatAppBrlyConPre) this.statapp = dpcheng.StatAppBrlyConPre;
				if (dpcheng.StatShrBrlyConPre) this.statshr = dpcheng.StatShrBrlyConPre;
				if (dpcheng.TagBrlyConPre) {
					Brly.unescapeBlock(dpcheng.TagBrlyConPre);
					this.tag = dpcheng.TagBrlyConPre;
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
				if (srefIxBrlyVDpch == "DpchEngBrlyConPreData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyConPreData") this.mergeDpchEngData(obj.dpcheng);
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
