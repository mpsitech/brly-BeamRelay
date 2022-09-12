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
					<PnlBrlyFltPre
						v-on:request="handleRequest"
						ref="PnlBrlyFltPre"
						:scrJref=statshr.scrJrefPre
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="12">
					<PnlBrlyFltDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyFltDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyFltFafAWaypoint
						v-on:request="handleRequest"
						ref="PnlBrlyFltFafAWaypoint"
						:scrJref=statshr.scrJrefFafAWaypoint
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyFlt1NConnection
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyFlt1NConnection"
						:scrJref=statshr.scrJref1NConnection
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyFltRef1NSegment
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyFltRef1NSegment"
						:scrJref=statshr.scrJrefRef1NSegment
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyFltEqp1NNode
						v-on:request="handleRequest"
						ref="PnlBrlyFltEqp1NNode"
						:scrJref=statshr.scrJrefEqp1NNode
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyFltMNLocation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyFltMNLocation"
						:scrJref=statshr.scrJrefMNLocation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyFltOrgMNFlight
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyFltOrgMNFlight"
						:scrJref=statshr.scrJrefOrgMNFlight
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyFltMNConnection
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyFltMNConnection"
						:scrJref=statshr.scrJrefMNConnection
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyFltEqpMNConnection
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyFltEqpMNConnection"
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
	import PnlBrlyFltPre from './PnlBrlyFltPre';
	import PnlBrlyFltDetail from './PnlBrlyFltDetail';
	import PnlBrlyFltFafAWaypoint from './PnlBrlyFltFafAWaypoint';
	import PnlBrlyFlt1NConnection from './PnlBrlyFlt1NConnection';
	import PnlBrlyFltRef1NSegment from './PnlBrlyFltRef1NSegment';
	import PnlBrlyFltEqp1NNode from './PnlBrlyFltEqp1NNode';
	import PnlBrlyFltMNLocation from './PnlBrlyFltMNLocation';
	import PnlBrlyFltOrgMNFlight from './PnlBrlyFltOrgMNFlight';
	import PnlBrlyFltMNConnection from './PnlBrlyFltMNConnection';
	import PnlBrlyFltEqpMNConnection from './PnlBrlyFltEqpMNConnection';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyFltRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyFltPre,
			PnlBrlyFltDetail,
			PnlBrlyFltFafAWaypoint,
			PnlBrlyFlt1NConnection,
			PnlBrlyFltRef1NSegment,
			PnlBrlyFltEqp1NNode,
			PnlBrlyFltMNLocation,
			PnlBrlyFltOrgMNFlight,
			PnlBrlyFltMNConnection,
			PnlBrlyFltEqpMNConnection
			/*
			*/
		},

		mounted() {
			//console.log("PnlBrlyFltRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyFltRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfBrlyFltRec) this.continf = dpcheng.ContInfBrlyFltRec;
				if (dpcheng.StatAppBrlyFltRec) this.statapp = dpcheng.StatAppBrlyFltRec;
				if (dpcheng.StatShrBrlyFltRec) this.statshr = dpcheng.StatShrBrlyFltRec;
				if (dpcheng.TagBrlyFltRec) {
					Brly.unescapeBlock(dpcheng.TagBrlyFltRec);
					this.tag = dpcheng.TagBrlyFltRec;
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
						if (obj.scrJref == this.statshr.scrJrefPre) this.$refs.PnlBrlyFltPre.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyFltDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefFafAWaypoint) this.$refs.PnlBrlyFltFafAWaypoint.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NConnection) this.$refs.PnlBrlyFlt1NConnection.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NSegment) this.$refs.PnlBrlyFltRef1NSegment.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefEqp1NNode) this.$refs.PnlBrlyFltEqp1NNode.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNLocation) this.$refs.PnlBrlyFltMNLocation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefOrgMNFlight) this.$refs.PnlBrlyFltOrgMNFlight.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNConnection) this.$refs.PnlBrlyFltMNConnection.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefEqpMNConnection) this.$refs.PnlBrlyFltEqpMNConnection.handleReply(obj);
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
				if (srefIxBrlyVDpch == "DpchEngBrlyFltRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyFltRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefPre) this.$refs.PnlBrlyFltPre.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyFltDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefFafAWaypoint) this.$refs.PnlBrlyFltFafAWaypoint.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NConnection) this.$refs.PnlBrlyFlt1NConnection.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NSegment) this.$refs.PnlBrlyFltRef1NSegment.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefEqp1NNode) this.$refs.PnlBrlyFltEqp1NNode.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNLocation) this.$refs.PnlBrlyFltMNLocation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefOrgMNFlight) this.$refs.PnlBrlyFltOrgMNFlight.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNConnection) this.$refs.PnlBrlyFltMNConnection.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefEqpMNConnection) this.$refs.PnlBrlyFltEqpMNConnection.handleUpdate(obj);
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
