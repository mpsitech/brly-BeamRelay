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
		name: 'PnlBrlyLocMap',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlBrlyLocMap.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyLocMapDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacBrlyLocMap"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppBrlyLocMapData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppBrlyLocMapData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacBrlyLocMap) this.contiac = dpcheng.ContIacBrlyLocMap;
				if (dpcheng.ContInfBrlyLocMap) this.continf = dpcheng.ContInfBrlyLocMap;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatShrBrlyLocMap) this.statshr = dpcheng.StatShrBrlyLocMap;
				if (dpcheng.TagBrlyLocMap) {
					Brly.unescapeBlock(dpcheng.TagBrlyLocMap);
					this.tag = dpcheng.TagBrlyLocMap;
				}
				if (dpcheng.ListBrlyQLocMapLeg) this.rstleg = dpcheng.ListBrlyQLocMapLeg;
				if (dpcheng.ListBrlyQLocMapProxLocation) this.rstproxlocation = dpcheng.ListBrlyQLocMapProxLocation;
				if (dpcheng.ListBrlyQLocMapVisLocation) this.rstvislocation = dpcheng.ListBrlyQLocMapVisLocation;
				if (dpcheng.StatShrQryBrlyLocMapLeg) this.statshrqryleg = dpcheng.StatShrQryBrlyLocMapLeg;
				if (dpcheng.StatShrQryBrlyLocMapProxLocation) this.statshrqryproxlocation = dpcheng.StatShrQryBrlyLocMapProxLocation;
				if (dpcheng.StatShrQryBrlyLocMapVisLocation) this.statshrqryvislocation = dpcheng.StatShrQryBrlyLocMapVisLocation;
				if (dpcheng.StgIacQryBrlyLocMapLeg) this.stgiacqryleg = dpcheng.StgIacQryBrlyLocMapLeg;
				if (dpcheng.StgIacQryBrlyLocMapProxLocation) this.stgiacqryproxlocation = dpcheng.StgIacQryBrlyLocMapProxLocation;
				if (dpcheng.StgIacQryBrlyLocMapVisLocation) this.stgiacqryvislocation = dpcheng.StgIacQryBrlyLocMapVisLocation;
				if (dpcheng.StgIacBrlyLocMap) this.stgiac = dpcheng.StgIacBrlyLocMap;
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
				if (srefIxBrlyVDpch == "DpchEngBrlyLocMapData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngBrlyLocMapImage: function(dpcheng) {
				/*
				<!-- IP handleDpchEngBrlyLocMapImage - BEGIN -->
				*/
				console.log("PnlBrlyLocMap.handleDpchEngBrlyLocMapImage()" + dpcheng);
				/*
				<!-- IP handleDpchEngBrlyLocMapImage - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxBrlyVDpch == "DpchEngBrlyLocMapImage") this.handleDpchEngBrlyLocMapImage(obj.dpcheng);
				else if (obj.srefIxBrlyVDpch == "DpchEngBrlyLocMapData") this.mergeDpchEngData(obj.dpcheng);
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

			rstleg: null,

			rstproxlocation: null,

			rstvislocation: null,

			statshrqryleg: null,

			statshrqryproxlocation: null,

			statshrqryvislocation: null,

			stgiacqryleg: null,

			stgiacqryproxlocation: null,

			stgiacqryvislocation: null,

			stgiac: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
