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
					<PnlBrlyRegDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyRegDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyRegADstswitch
						v-on:request="handleRequest"
						ref="PnlBrlyRegADstswitch"
						:scrJref=statshr.scrJrefADstswitch
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyReg1NLocation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyReg1NLocation"
						:scrJref=statshr.scrJref1NLocation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyRegSup1NRegion
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyRegSup1NRegion"
						:scrJref=statshr.scrJrefSup1NRegion
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
	import PnlBrlyRegDetail from './PnlBrlyRegDetail';
	import PnlBrlyRegADstswitch from './PnlBrlyRegADstswitch';
	import PnlBrlyReg1NLocation from './PnlBrlyReg1NLocation';
	import PnlBrlyRegSup1NRegion from './PnlBrlyRegSup1NRegion';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyRegRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyRegDetail,
			PnlBrlyRegADstswitch,
			PnlBrlyReg1NLocation,
			PnlBrlyRegSup1NRegion
			/*
			*/
		},

		mounted() {
			//console.log("PnlBrlyRegRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyRegRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfBrlyRegRec) this.continf = dpcheng.ContInfBrlyRegRec;
				if (dpcheng.StatAppBrlyRegRec) this.statapp = dpcheng.StatAppBrlyRegRec;
				if (dpcheng.StatShrBrlyRegRec) this.statshr = dpcheng.StatShrBrlyRegRec;
				if (dpcheng.TagBrlyRegRec) {
					Brly.unescapeBlock(dpcheng.TagBrlyRegRec);
					this.tag = dpcheng.TagBrlyRegRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyRegDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefADstswitch) this.$refs.PnlBrlyRegADstswitch.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NLocation) this.$refs.PnlBrlyReg1NLocation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NRegion) this.$refs.PnlBrlyRegSup1NRegion.handleReply(obj);
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
				if (srefIxBrlyVDpch == "DpchEngBrlyRegRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyRegRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyRegDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefADstswitch) this.$refs.PnlBrlyRegADstswitch.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NLocation) this.$refs.PnlBrlyReg1NLocation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NRegion) this.$refs.PnlBrlyRegSup1NRegion.handleUpdate(obj);
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
