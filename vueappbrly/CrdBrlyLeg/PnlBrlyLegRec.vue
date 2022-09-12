<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="9">
					<div class="caption text-decoration-underline">{{tag.Cpt}}</div>
					<div>{{continf.TxtRef}}</div>
				</v-col>
				<v-col cols="3" align="end">
					<v-btn
						v-if="statshr.srefIxBrlyVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeCLick')"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					<v-btn
						v-if="statshr.srefIxBrlyVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						:disabled="!statshr.ButRegularizeActive"
						v-on:click="handleButClick('ButRegularizeClick')"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxBrlyVExpstate=='regd'"
		>
			<v-row>
				<v-col cols="12" md="12">
					<PnlBrlyLegPre
						v-on:request="handleRequest"
						ref="PnlBrlyLegPre"
						:scrJref=statshr.scrJrefPre
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="12">
					<PnlBrlyLegDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLegDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="12">
					<PnlBrlyLegMap
						v-on:request="handleRequest"
						ref="PnlBrlyLegMap"
						:scrJref=statshr.scrJrefMap
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyLeg1NFlight
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLeg1NFlight"
						:scrJref=statshr.scrJref1NFlight
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLegCor1NConnection
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLegCor1NConnection"
						:scrJref=statshr.scrJrefCor1NConnection
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLegMNLocation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLegMNLocation"
						:scrJref=statshr.scrJrefMNLocation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLegOrgMNLeg
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLegOrgMNLeg"
						:scrJref=statshr.scrJrefOrgMNLeg
					/>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyLegPre from './PnlBrlyLegPre';
	import PnlBrlyLegDetail from './PnlBrlyLegDetail';
	import PnlBrlyLegMap from './PnlBrlyLegMap';
	import PnlBrlyLeg1NFlight from './PnlBrlyLeg1NFlight';
	import PnlBrlyLegCor1NConnection from './PnlBrlyLegCor1NConnection';
	import PnlBrlyLegMNLocation from './PnlBrlyLegMNLocation';
	import PnlBrlyLegOrgMNLeg from './PnlBrlyLegOrgMNLeg';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyLegRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyLegPre,
			PnlBrlyLegDetail,
			PnlBrlyLegMap,
			PnlBrlyLeg1NFlight,
			PnlBrlyLegCor1NConnection,
			PnlBrlyLegMNLocation,
			PnlBrlyLegOrgMNLeg
			/*
			*/
		},

		mounted() {
			//console.log("PnlBrlyLegRec.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppBrlyInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppBrlyLegRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfBrlyLegRec) this.continf = dpcheng.ContInfBrlyLegRec;
				if (dpcheng.StatAppBrlyLegRec) this.statapp = dpcheng.StatAppBrlyLegRec;
				if (dpcheng.StatShrBrlyLegRec) this.statshr = dpcheng.StatShrBrlyLegRec;
				if (dpcheng.TagBrlyLegRec) {
					Brly.unescapeBlock(dpcheng.TagBrlyLegRec);
					this.tag = dpcheng.TagBrlyLegRec;
				}
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				//console.log(obj);
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
					else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxBrlyVDpch, obj.dpcheng);

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						/*
						*/
						if (obj.scrJref == this.statshr.scrJrefPre) this.$refs.PnlBrlyLegPre.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyLegDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMap) this.$refs.PnlBrlyLegMap.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NFlight) this.$refs.PnlBrlyLeg1NFlight.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefCor1NConnection) this.$refs.PnlBrlyLegCor1NConnection.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNLocation) this.$refs.PnlBrlyLegMNLocation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefOrgMNLeg) this.$refs.PnlBrlyLegOrgMNLeg.handleReply(obj);
						/*
						*/
					}
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxBrlyVDpch, dpcheng) {
				if (srefIxBrlyVDpch == "DpchEngBrlyLegRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyLegRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefPre) this.$refs.PnlBrlyLegPre.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyLegDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMap) this.$refs.PnlBrlyLegMap.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NFlight) this.$refs.PnlBrlyLeg1NFlight.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefCor1NConnection) this.$refs.PnlBrlyLegCor1NConnection.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNLocation) this.$refs.PnlBrlyLegMNLocation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefOrgMNLeg) this.$refs.PnlBrlyLegOrgMNLeg.handleUpdate(obj);
						/*
						*/
						else processed = false;
					}
				}

				return processed
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

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
