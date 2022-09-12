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
					<PnlBrlyUsrDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyUsrDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyUsrAAccess
						v-on:request="handleRequest"
						ref="PnlBrlyUsrAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlBrlyUsr1NSession
						v-on:request="handleRequest"
						ref="PnlBrlyUsr1NSession"
						:scrJref=statshr.scrJref1NSession
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlBrlyUsrMNUsergroup
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlBrlyUsrMNUsergroup"
						:scrJref=statshr.scrJrefMNUsergroup
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
	import PnlBrlyUsrDetail from './PnlBrlyUsrDetail';
	import PnlBrlyUsrAAccess from './PnlBrlyUsrAAccess';
	import PnlBrlyUsr1NSession from './PnlBrlyUsr1NSession';
	import PnlBrlyUsrMNUsergroup from './PnlBrlyUsrMNUsergroup';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlBrlyUsrRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyUsrDetail,
			PnlBrlyUsrAAccess,
			PnlBrlyUsr1NSession,
			PnlBrlyUsrMNUsergroup
			/*
			*/
		},

		mounted() {
			//console.log("PnlBrlyUsrRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppBrlyUsrRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfBrlyUsrRec) this.continf = dpcheng.ContInfBrlyUsrRec;
				if (dpcheng.StatAppBrlyUsrRec) this.statapp = dpcheng.StatAppBrlyUsrRec;
				if (dpcheng.StatShrBrlyUsrRec) this.statshr = dpcheng.StatShrBrlyUsrRec;
				if (dpcheng.TagBrlyUsrRec) {
					Brly.unescapeBlock(dpcheng.TagBrlyUsrRec);
					this.tag = dpcheng.TagBrlyUsrRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyUsrDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlBrlyUsrAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlBrlyUsr1NSession.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlBrlyUsrMNUsergroup.handleReply(obj);
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
				if (srefIxBrlyVDpch == "DpchEngBrlyUsrRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyUsrRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxBrlyVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlBrlyUsrDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlBrlyUsrAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlBrlyUsr1NSession.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlBrlyUsrMNUsergroup.handleUpdate(obj);
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
