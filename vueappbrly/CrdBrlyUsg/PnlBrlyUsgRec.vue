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
					<PnlBrlyUsgDetail
						v-on:request="handleRequest"
						ref="PnlBrlyUsgDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyUsgAAccess
						v-on:request="handleRequest"
						ref="PnlBrlyUsgAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyUsgMNUser
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyUsgMNUser"
						:scrJref=statshr.scrJrefMNUser
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
	import PnlBrlyUsgDetail from './PnlBrlyUsgDetail';
	import PnlBrlyUsgAAccess from './PnlBrlyUsgAAccess';
	import PnlBrlyUsgMNUser from './PnlBrlyUsgMNUser';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyUsgRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyUsgDetail,
			PnlBrlyUsgAAccess,
			PnlBrlyUsgMNUser
			/*
			*/
		},

		mounted() {
			//console.log("PnlBrlyUsgRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyUsgRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfBrlyUsgRec) this.continf = dpcheng.ContInfBrlyUsgRec;
				if (dpcheng.StatAppBrlyUsgRec) this.statapp = dpcheng.StatAppBrlyUsgRec;
				if (dpcheng.StatShrBrlyUsgRec) this.statshr = dpcheng.StatShrBrlyUsgRec;
				if (dpcheng.TagBrlyUsgRec) {
					Brly.unescapeBlock(dpcheng.TagBrlyUsgRec);
					this.tag = dpcheng.TagBrlyUsgRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyUsgDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlBrlyUsgAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUser) this.$refs.PnlBrlyUsgMNUser.handleReply(obj);
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
				if (srefIxBrlyVDpch == "DpchEngBrlyUsgRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyUsgRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyUsgDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlBrlyUsgAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUser) this.$refs.PnlBrlyUsgMNUser.handleUpdate(obj);
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
