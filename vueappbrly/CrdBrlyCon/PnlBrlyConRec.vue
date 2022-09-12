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
					<PnlBrlyConPre
						v-on:request="handleRequest"
						ref="PnlBrlyConPre"
						:scrJref=statshr.scrJrefPre
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="12">
					<PnlBrlyConDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyConDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="12">
					<PnlBrlyConMap
						v-on:request="handleRequest"
						ref="PnlBrlyConMap"
						:scrJref=statshr.scrJrefMap
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyCon1NRelay
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyCon1NRelay"
						:scrJref=statshr.scrJref1NRelay
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyConRef1NSegment
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyConRef1NSegment"
						:scrJref=statshr.scrJrefRef1NSegment
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyConConMNEquipment
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyConConMNEquipment"
						:scrJref=statshr.scrJrefConMNEquipment
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyConMNFlight
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyConMNFlight"
						:scrJref=statshr.scrJrefMNFlight
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyConMNSegment
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyConMNSegment"
						:scrJref=statshr.scrJrefMNSegment
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
	import PnlBrlyConPre from './PnlBrlyConPre';
	import PnlBrlyConDetail from './PnlBrlyConDetail';
	import PnlBrlyConMap from './PnlBrlyConMap';
	import PnlBrlyCon1NRelay from './PnlBrlyCon1NRelay';
	import PnlBrlyConRef1NSegment from './PnlBrlyConRef1NSegment';
	import PnlBrlyConConMNEquipment from './PnlBrlyConConMNEquipment';
	import PnlBrlyConMNFlight from './PnlBrlyConMNFlight';
	import PnlBrlyConMNSegment from './PnlBrlyConMNSegment';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyConRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyConPre,
			PnlBrlyConDetail,
			PnlBrlyConMap,
			PnlBrlyCon1NRelay,
			PnlBrlyConRef1NSegment,
			PnlBrlyConConMNEquipment,
			PnlBrlyConMNFlight,
			PnlBrlyConMNSegment
			/*
			*/
		},

		mounted() {
			//console.log("PnlBrlyConRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyConRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfBrlyConRec) this.continf = dpcheng.ContInfBrlyConRec;
				if (dpcheng.StatAppBrlyConRec) this.statapp = dpcheng.StatAppBrlyConRec;
				if (dpcheng.StatShrBrlyConRec) this.statshr = dpcheng.StatShrBrlyConRec;
				if (dpcheng.TagBrlyConRec) {
					Brly.unescapeBlock(dpcheng.TagBrlyConRec);
					this.tag = dpcheng.TagBrlyConRec;
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
						if (obj.scrJref == this.statshr.scrJrefPre) this.$refs.PnlBrlyConPre.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyConDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMap) this.$refs.PnlBrlyConMap.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRelay) this.$refs.PnlBrlyCon1NRelay.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NSegment) this.$refs.PnlBrlyConRef1NSegment.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefConMNEquipment) this.$refs.PnlBrlyConConMNEquipment.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNFlight) this.$refs.PnlBrlyConMNFlight.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNSegment) this.$refs.PnlBrlyConMNSegment.handleReply(obj);
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
				if (srefIxBrlyVDpch == "DpchEngBrlyConRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyConRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefPre) this.$refs.PnlBrlyConPre.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyConDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMap) this.$refs.PnlBrlyConMap.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRelay) this.$refs.PnlBrlyCon1NRelay.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NSegment) this.$refs.PnlBrlyConRef1NSegment.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefConMNEquipment) this.$refs.PnlBrlyConConMNEquipment.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNFlight) this.$refs.PnlBrlyConMNFlight.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNSegment) this.$refs.PnlBrlyConMNSegment.handleUpdate(obj);
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
