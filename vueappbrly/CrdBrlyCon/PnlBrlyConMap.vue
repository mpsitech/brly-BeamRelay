<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;
					<v-btn
						v-if="statshr.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDetachClick')"
						:value="1"
					>
						{{tag.ButDetach}}
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButAttachClick')"
						:value="1"
					>
						{{tag.ButAttach}}
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxBrlyVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxBrlyVExpstate=='regd'"
		>
			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButHomeClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButHome}}
					</v-btn>
				</v-col>
			</v-row>

			<v-slider
				class="my-1"
				v-model="contiac.SldScl"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptScl"
				:min="statshr.SldSclMin"
				:max="statshr.SldSclMax"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldScl"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButRefreshClick')"
						class="my-1"
						color="primary"
					>
						{{tag.ButRefresh}}
					</v-btn>
				</v-col>
			</v-row>

			<v-btn
				download
				:href="hrefDld"
				class="my-1"
				color="primary"
			>
				{{tag.Dld}}
			</v-btn>
		</v-card-text>
	</v-card>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyConMap',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyConMap.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyConMapDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyConMap"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyConMapData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyConMapData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyConMap) this.contiac = dpcheng.ContIacBrlyConMap;
				if (dpcheng.ContInfBrlyConMap) this.continf = dpcheng.ContInfBrlyConMap;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatShrBrlyConMap) this.statshr = dpcheng.StatShrBrlyConMap;
				if (dpcheng.TagBrlyConMap) {
					Brly.unescapeBlock(dpcheng.TagBrlyConMap);
					this.tag = dpcheng.TagBrlyConMap;
				}
				if (dpcheng.ListBrlyQConMapFlight) this.rstflight = dpcheng.ListBrlyQConMapFlight;
				if (dpcheng.ListBrlyQConMapLeg) this.rstleg = dpcheng.ListBrlyQConMapLeg;
				if (dpcheng.ListBrlyQConMapLocation) this.rstlocation = dpcheng.ListBrlyQConMapLocation;
				if (dpcheng.ListBrlyQConMapNode) this.rstnode = dpcheng.ListBrlyQConMapNode;
				if (dpcheng.ListBrlyQConMapRelay) this.rstrelay = dpcheng.ListBrlyQConMapRelay;
				if (dpcheng.StatShrQryBrlyConMapFlight) this.statshrqryflight = dpcheng.StatShrQryBrlyConMapFlight;
				if (dpcheng.StatShrQryBrlyConMapLeg) this.statshrqryleg = dpcheng.StatShrQryBrlyConMapLeg;
				if (dpcheng.StatShrQryBrlyConMapLocation) this.statshrqrylocation = dpcheng.StatShrQryBrlyConMapLocation;
				if (dpcheng.StatShrQryBrlyConMapNode) this.statshrqrynode = dpcheng.StatShrQryBrlyConMapNode;
				if (dpcheng.StatShrQryBrlyConMapRelay) this.statshrqryrelay = dpcheng.StatShrQryBrlyConMapRelay;
				if (dpcheng.StgIacQryBrlyConMapFlight) this.stgiacqryflight = dpcheng.StgIacQryBrlyConMapFlight;
				if (dpcheng.StgIacQryBrlyConMapLeg) this.stgiacqryleg = dpcheng.StgIacQryBrlyConMapLeg;
				if (dpcheng.StgIacQryBrlyConMapLocation) this.stgiacqrylocation = dpcheng.StgIacQryBrlyConMapLocation;
				if (dpcheng.StgIacQryBrlyConMapNode) this.stgiacqrynode = dpcheng.StgIacQryBrlyConMapNode;
				if (dpcheng.StgIacQryBrlyConMapRelay) this.stgiacqryrelay = dpcheng.StgIacQryBrlyConMapRelay;
				if (dpcheng.StatAppBrlyConMap) this.statapp = dpcheng.StatAppBrlyConMap;
				if (dpcheng.StgIacBrlyConMap) this.stgiac = dpcheng.StgIacBrlyConMap;
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
				if (srefIxBrlyVDpch == "DpchEngBrlyConMapData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngBrlyConMapImage: function(dpcheng) {
				/*
				<!-- IP handleDpchEngBrlyConMapImage - BEGIN -->
				*/
				console.log("PnlBrlyConMap.handleDpchEngBrlyConMapImage()" + dpcheng);
				/*
				<!-- IP handleDpchEngBrlyConMapImage - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyConMapImage") this.handleDpchEngBrlyConMapImage(obj.dpcheng);
				else if (obj.srefIxBrlyVDpch == "DpchEngBrlyConMapData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			hrefDld: function() {
				return window.location.protocol + '//' + Brly.hostname() + ':' + Brly.appsrvport() + '/download/' + this.scrJref;
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFSge: null,

			statshr: null,

			tag: null,

			rstflight: null,

			rstleg: null,

			rstlocation: null,

			rstnode: null,

			rstrelay: null,

			statshrqryflight: null,

			statshrqryleg: null,

			statshrqrylocation: null,

			statshrqrynode: null,

			statshrqryrelay: null,

			stgiacqryflight: null,

			stgiacqryleg: null,

			stgiacqrylocation: null,

			stgiacqrynode: null,

			stgiacqryrelay: null,

			statapp: null,

			stgiac: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
