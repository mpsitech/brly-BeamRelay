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
					<PnlBrlySegPre
						v-on:request="handleRequest"
						ref="PnlBrlySegPre"
						:scrJref=statshr.scrJrefPre
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="12">
					<PnlBrlySegDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlySegDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlySegOrgMNSegment
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlySegOrgMNSegment"
						:scrJref=statshr.scrJrefOrgMNSegment
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlySegMNLocation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlySegMNLocation"
						:scrJref=statshr.scrJrefMNLocation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlySegMNConnection
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlySegMNConnection"
						:scrJref=statshr.scrJrefMNConnection
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
	import PnlBrlySegPre from './PnlBrlySegPre';
	import PnlBrlySegDetail from './PnlBrlySegDetail';
	import PnlBrlySegOrgMNSegment from './PnlBrlySegOrgMNSegment';
	import PnlBrlySegMNLocation from './PnlBrlySegMNLocation';
	import PnlBrlySegMNConnection from './PnlBrlySegMNConnection';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlySegRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlySegPre,
			PnlBrlySegDetail,
			PnlBrlySegOrgMNSegment,
			PnlBrlySegMNLocation,
			PnlBrlySegMNConnection
			/*
			*/
		},

		mounted() {
			//console.log("PnlBrlySegRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlySegRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfBrlySegRec) this.continf = dpcheng.ContInfBrlySegRec;
				if (dpcheng.StatAppBrlySegRec) this.statapp = dpcheng.StatAppBrlySegRec;
				if (dpcheng.StatShrBrlySegRec) this.statshr = dpcheng.StatShrBrlySegRec;
				if (dpcheng.TagBrlySegRec) {
					Brly.unescapeBlock(dpcheng.TagBrlySegRec);
					this.tag = dpcheng.TagBrlySegRec;
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
						if (obj.scrJref == this.statshr.scrJrefPre) this.$refs.PnlBrlySegPre.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlySegDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefOrgMNSegment) this.$refs.PnlBrlySegOrgMNSegment.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNLocation) this.$refs.PnlBrlySegMNLocation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNConnection) this.$refs.PnlBrlySegMNConnection.handleReply(obj);
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
				if (srefIxBrlyVDpch == "DpchEngBrlySegRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlySegRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefPre) this.$refs.PnlBrlySegPre.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlySegDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefOrgMNSegment) this.$refs.PnlBrlySegOrgMNSegment.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNLocation) this.$refs.PnlBrlySegMNLocation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNConnection) this.$refs.PnlBrlySegMNConnection.handleUpdate(obj);
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
