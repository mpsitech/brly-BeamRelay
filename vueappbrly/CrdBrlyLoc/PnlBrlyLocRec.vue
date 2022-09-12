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
					<PnlBrlyLocDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="12">
					<PnlBrlyLocMap
						v-on:request="handleRequest"
						ref="PnlBrlyLocMap"
						:scrJref=statshr.scrJrefMap
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyLocBgn1NLeg
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocBgn1NLeg"
						:scrJref=statshr.scrJrefBgn1NLeg
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLocEnd1NLeg
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocEnd1NLeg"
						:scrJref=statshr.scrJrefEnd1NLeg
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLocEqp1NNode
						v-on:request="handleRequest"
						ref="PnlBrlyLocEqp1NNode"
						:scrJref=statshr.scrJrefEqp1NNode
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLocMNSegment
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocMNSegment"
						:scrJref=statshr.scrJrefMNSegment
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLocMNFlight
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocMNFlight"
						:scrJref=statshr.scrJrefMNFlight
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLocMNLeg
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocMNLeg"
						:scrJref=statshr.scrJrefMNLeg
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLocVisOrgMNLocation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocVisOrgMNLocation"
						:scrJref=statshr.scrJrefVisOrgMNLocation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLocProxOrgMNLocation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocProxOrgMNLocation"
						:scrJref=statshr.scrJrefProxOrgMNLocation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyLocEqpMNConnection
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyLocEqpMNConnection"
						:scrJref=statshr.scrJrefEqpMNConnection
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
	import PnlBrlyLocDetail from './PnlBrlyLocDetail';
	import PnlBrlyLocMap from './PnlBrlyLocMap';
	import PnlBrlyLocBgn1NLeg from './PnlBrlyLocBgn1NLeg';
	import PnlBrlyLocEnd1NLeg from './PnlBrlyLocEnd1NLeg';
	import PnlBrlyLocEqp1NNode from './PnlBrlyLocEqp1NNode';
	import PnlBrlyLocMNSegment from './PnlBrlyLocMNSegment';
	import PnlBrlyLocMNFlight from './PnlBrlyLocMNFlight';
	import PnlBrlyLocMNLeg from './PnlBrlyLocMNLeg';
	import PnlBrlyLocVisOrgMNLocation from './PnlBrlyLocVisOrgMNLocation';
	import PnlBrlyLocProxOrgMNLocation from './PnlBrlyLocProxOrgMNLocation';
	import PnlBrlyLocEqpMNConnection from './PnlBrlyLocEqpMNConnection';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyLocRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyLocDetail,
			PnlBrlyLocMap,
			PnlBrlyLocBgn1NLeg,
			PnlBrlyLocEnd1NLeg,
			PnlBrlyLocEqp1NNode,
			PnlBrlyLocMNSegment,
			PnlBrlyLocMNFlight,
			PnlBrlyLocMNLeg,
			PnlBrlyLocVisOrgMNLocation,
			PnlBrlyLocProxOrgMNLocation,
			PnlBrlyLocEqpMNConnection
			/*
			*/
		},

		mounted() {
			//console.log("PnlBrlyLocRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyLocRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfBrlyLocRec) this.continf = dpcheng.ContInfBrlyLocRec;
				if (dpcheng.StatAppBrlyLocRec) this.statapp = dpcheng.StatAppBrlyLocRec;
				if (dpcheng.StatShrBrlyLocRec) this.statshr = dpcheng.StatShrBrlyLocRec;
				if (dpcheng.TagBrlyLocRec) {
					Brly.unescapeBlock(dpcheng.TagBrlyLocRec);
					this.tag = dpcheng.TagBrlyLocRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyLocDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMap) this.$refs.PnlBrlyLocMap.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefBgn1NLeg) this.$refs.PnlBrlyLocBgn1NLeg.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefEnd1NLeg) this.$refs.PnlBrlyLocEnd1NLeg.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefEqp1NNode) this.$refs.PnlBrlyLocEqp1NNode.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNSegment) this.$refs.PnlBrlyLocMNSegment.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNFlight) this.$refs.PnlBrlyLocMNFlight.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNLeg) this.$refs.PnlBrlyLocMNLeg.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefVisOrgMNLocation) this.$refs.PnlBrlyLocVisOrgMNLocation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefProxOrgMNLocation) this.$refs.PnlBrlyLocProxOrgMNLocation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefEqpMNConnection) this.$refs.PnlBrlyLocEqpMNConnection.handleReply(obj);
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
				if (srefIxBrlyVDpch == "DpchEngBrlyLocRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyLocRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyLocDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMap) this.$refs.PnlBrlyLocMap.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefBgn1NLeg) this.$refs.PnlBrlyLocBgn1NLeg.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefEnd1NLeg) this.$refs.PnlBrlyLocEnd1NLeg.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefEqp1NNode) this.$refs.PnlBrlyLocEqp1NNode.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNSegment) this.$refs.PnlBrlyLocMNSegment.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNFlight) this.$refs.PnlBrlyLocMNFlight.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNLeg) this.$refs.PnlBrlyLocMNLeg.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefVisOrgMNLocation) this.$refs.PnlBrlyLocVisOrgMNLocation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefProxOrgMNLocation) this.$refs.PnlBrlyLocProxOrgMNLocation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefEqpMNConnection) this.$refs.PnlBrlyLocEqpMNConnection.handleUpdate(obj);
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
