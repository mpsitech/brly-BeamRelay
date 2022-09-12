<template>
	<v-layout class="fill-height">
		<v-navigation-drawer app floating width="350" class="elevation-1">
			<CrdBrlyNav
				v-on:crdopen="handleCrdopen"
				v-on:dlgopen="handleDlgopen"
				v-on:dlgclose="handleDlgclose"
				v-on:request="handleRequestFromCrdnav"
				ref="CrdBrlyNav"
				:scrJref=scrJrefCrdnav
			/>
		</v-navigation-drawer>
		<component
			:key="srefCrd"
			v-bind:is="content"
			v-on:crdopen="handleCrdopen"
			v-on:dlgopen="handleDlgopen"
			v-on:dlgclose="handleDlgclose"
			v-on:request="handleRequestFromCrd"
			v-on:upload="handleUpload"
			ref="content"
			:scrJref=scrJrefCrd
		/>
		<v-dialog
			v-model="alert"
			v-if="alert"
			persistent
			width="500"
		>
			<v-card>
				<v-card-title>
					{{alert.TxtCpt}}
				</v-card-title>
				<v-card-text>
					<div
						v-for="(TxtMsg, ix) in alert.TxtMsgs"
						:key="ix"
					>
						{{TxtMsg ? TxtMsg : '&nbsp;'}}
					</div>
				</v-card-text>
				<v-divider/>
				<v-card-actions>
					<v-spacer/>
					<v-btn
						class="primary"
						v-for="Fi in alert.FeedFMcbAlert"
						:key="Fi.num"
						v-on:click="handleAlertAction(Fi.num)"
					>
						{{Fi.tit1}}
					</v-btn>
				</v-card-actions>
			</v-card>
		</v-dialog>
		<v-dialog
			v-model="dialog"
			v-if="dialog"
			persistent
			width="1200"
		>
			<component
				:key="srefDlg"
				v-bind:is="dialog"
				v-on:upload="handleUpload"
				v-on:request="handleRequestFromDlg"
				ref="dialog"
				:scrJref=scrJrefDlg
			/>
		</v-dialog>
	</v-layout>
</template>

<script>
	import axios from 'axios'

	import Brly from '../scripts/Brly';

	/*
	*/
	import CrdBrlyUsg from './CrdBrlyUsg/CrdBrlyUsg';
	import CrdBrlyUsr from './CrdBrlyUsr/CrdBrlyUsr';
	import CrdBrlyPrs from './CrdBrlyPrs/CrdBrlyPrs';
	import CrdBrlyFil from './CrdBrlyFil/CrdBrlyFil';
	import CrdBrlyOpr from './CrdBrlyOpr/CrdBrlyOpr';
	import CrdBrlyPty from './CrdBrlyPty/CrdBrlyPty';
	import CrdBrlyNav from './CrdBrlyNav/CrdBrlyNav';
	import DlgBrlyNavLoaini from './CrdBrlyNav/DlgBrlyNavLoaini';
	import CrdBrlyReg from './CrdBrlyReg/CrdBrlyReg';
	import CrdBrlyLoc from './CrdBrlyLoc/CrdBrlyLoc';
	import CrdBrlyLeg from './CrdBrlyLeg/CrdBrlyLeg';
	import DlgBrlyLegNew from './CrdBrlyLeg/DlgBrlyLegNew';
	import CrdBrlyTtb from './CrdBrlyTtb/CrdBrlyTtb';
	import DlgBrlyTtbImpflt from './CrdBrlyTtb/DlgBrlyTtbImpflt';
	import DlgBrlyTtbNew from './CrdBrlyTtb/DlgBrlyTtbNew';
	import DlgBrlyTtbTrlorig from './CrdBrlyTtb/DlgBrlyTtbTrlorig';
	import CrdBrlyFlt from './CrdBrlyFlt/CrdBrlyFlt';
	import CrdBrlySeg from './CrdBrlySeg/CrdBrlySeg';
	import CrdBrlyCon from './CrdBrlyCon/CrdBrlyCon';
	import DlgBrlyConNew from './CrdBrlyCon/DlgBrlyConNew';
	import CrdBrlyRly from './CrdBrlyRly/CrdBrlyRly';
	/*
	*/

	const dpch = axios.create({
		baseURL: window.location.protocol + "//" + Brly.hostname() + ":" + Brly.appsrvport() + "/dpch"
	})

	const notify = axios.create({
		baseURL: window.location.protocol + "//" + Brly.hostname() + ":" + Brly.appsrvport() + "/notify/json"
	})

	export default {
		name: 'SessBrly',

		props: {
			scrJrefSess: String,
			scrJrefCrdnav: String,

			srefCrd_initial: String,
			scrJrefCrd_initial: String
		},

		components: {
			/*
			*/
			CrdBrlyUsg,
			CrdBrlyUsr,
			CrdBrlyPrs,
			CrdBrlyFil,
			CrdBrlyOpr,
			CrdBrlyPty,
			CrdBrlyNav,
			DlgBrlyNavLoaini,
			CrdBrlyReg,
			CrdBrlyLoc,
			CrdBrlyLeg,
			DlgBrlyLegNew,
			CrdBrlyTtb,
			DlgBrlyTtbImpflt,
			DlgBrlyTtbNew,
			DlgBrlyTtbTrlorig,
			CrdBrlyFlt,
			CrdBrlySeg,
			CrdBrlyCon,
			DlgBrlyConNew,
			CrdBrlyRly
			/*
			*/
		},

		beforeMount() {
			this.srefCrd = this.srefCrd_initial;
			this.scrJrefCrd = this.scrJrefCrd_initial;

			this.content = this.srefCrd_initial;

			this.iterateNotify();
		},

		methods: {
			showAlert(dpcheng) {
				let continf = dpcheng.ContInfBrlyAlert;

				Brly.unescapeBlock(continf);

				dpcheng.TxtCpt = continf.TxtCpt; delete continf.TxtCpt;

				var i = 12;
				if (continf.TxtMsg12 == "") {
					i--;
					if (continf.TxtMsg11 == "") {
						i--;
						if (continf.TxtMsg10 == "") {
							i--;
							if (continf.TxtMsg9 == "") {
								i--;
								if (continf.TxtMsg8 == "") {
									i--;
									if (continf.TxtMsg7 == "") {
										i--;
										if (continf.TxtMsg6 == "") {
											i--;
											if (continf.TxtMsg5 == "") {
												i--;
												if (continf.TxtMsg4 == "") {
													i--;
													if (continf.TxtMsg3 == "") {
														i--;
														if (continf.TxtMsg2 == "") {
															i--;
															if (continf.TxtMsg1 == "") i--;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}

				dpcheng.TxtMsgs = new Array();
				if (i > 0) dpcheng.TxtMsgs.push(continf.TxtMsg1);
				if (i > 1) dpcheng.TxtMsgs.push(continf.TxtMsg2);
				if (i > 2) dpcheng.TxtMsgs.push(continf.TxtMsg3);
				if (i > 3) dpcheng.TxtMsgs.push(continf.TxtMsg4);
				if (i > 4) dpcheng.TxtMsgs.push(continf.TxtMsg5);
				if (i > 5) dpcheng.TxtMsgs.push(continf.TxtMsg6);
				if (i > 6) dpcheng.TxtMsgs.push(continf.TxtMsg7);
				if (i > 7) dpcheng.TxtMsgs.push(continf.TxtMsg8);
				if (i > 8) dpcheng.TxtMsgs.push(continf.TxtMsg9);
				if (i > 9) dpcheng.TxtMsgs.push(continf.TxtMsg10);
				if (i > 10) dpcheng.TxtMsgs.push(continf.TxtMsg11);
				if (i > 11) dpcheng.TxtMsgs.push(continf.TxtMsg12);

				delete continf.TxtMsg1;
				delete continf.TxtMsg2;
				delete continf.TxtMsg3;
				delete continf.TxtMsg4;
				delete continf.TxtMsg5;
				delete continf.TxtMsg6;
				delete continf.TxtMsg7;
				delete continf.TxtMsg8;
				delete continf.TxtMsg9;
				delete continf.TxtMsg10;
				delete continf.TxtMsg11;
				delete continf.TxtMsg12;

				this.alert = dpcheng;
			},

			handleAlertAction: function(num) {
				const dpchapp = {
					"DpchAppBrlyAlert": {
						"scrJref": this.alert.scrJref,
						"numFMcb": num
					}
				};
	
				this.handleRequest({scrJref: this.alert.scrJref, dpchapp: dpchapp, then: ""}, false);

				this.alert = null;

				this.$refs.CrdBrlyNav.handleAlrdlgclose();
			},

			handleCrdopen: function(obj) {
				//console.log("SessBrly.handleCrdopen() with " + obj.srefCrd);

				if ((obj.srefCrd != this.content) || obj.newtabNotInplace) {
					if (!obj.newtabNotInplace) {
						//console.log("SessBrly.handleCrdopen() new card in-place");

						this.srefCrd = obj.srefCrd;
						this.scrJrefCrd = obj.scrJrefCrd;

						this.content = obj.srefCrd;

						this.$refs.CrdBrlyNav.handleCrdopen(obj)

					} else {
						//console.log("SessBrly.handleCrdopen() new card in new tab");

						var paramBegin = window.location.href.indexOf("?");
						var url = window.location.href.substring(0, (paramBegin == -1) ? window.location.href.length : paramBegin);
						window.open(url + "?scrJrefCrdnav=" + this.scrJrefCrdnav + "&srefCrd=" + obj.srefCrd + "&scrJrefCrd=" + obj.scrJrefCrd, "_blank");
					}
				}
			},

			handleDlgopen: function(obj) {
				if (obj.srefDlg != this.dialog) {
					this.srefDlg = obj.srefDlg;
					this.scrJrefDlg = obj.scrJrefDlg;

					this.dialog = obj.srefDlg;
				}
			},

			handleDlgclose: function() {
				this.srefDlg = "";
				this.scrJrefDlg = "";

				this.dialog = null;

				this.$refs.CrdBrlyNav.handleAlrdlgclose();
			},

			handleRequestFromCrdnav: function(obj) {
				this.handleRequest(obj, false, false);
			},

			handleRequestFromCrd: function(obj) {
				this.handleRequest(obj, false, true);
			},

			handleRequestFromDlg: function(obj) {
				this.handleRequest(obj, true, false);
			},

			handleRequest: function(obj, srcDlgNotCrd, srcCrdNotCrdnav) {
				const data = "json=" + encodeURIComponent(JSON.stringify(obj.dpchapp));

				var vm = this;

				dpch.post('', data).then(function (response) {
					const scrJref = obj.dpchapp[Object.keys(obj.dpchapp)[0]].scrJref;
					const srefIxBrlyVDpch = Object.keys(response.data)[0];
					const dpcheng = response.data[srefIxBrlyVDpch];

					const target = (srcDlgNotCrd) ? vm.$refs.dialog : (srcCrdNotCrdnav) ? vm.$refs.content : vm.$refs.CrdBrlyNav;
					if (target) {
						target.handleReply({scrJref: scrJref, srefIxBrlyVDpch: srefIxBrlyVDpch, dpcheng: dpcheng, then: obj.then});
						if (dpcheng.scrJref == vm.scrJrefCrd) {
							if (target != vm.$refs.CrdBrlyNav) vm.$refs.CrdBrlyNav.handleUpdate({srefIxBrlyVDpch: srefIxBrlyVDpch, dpcheng: dpcheng});
							else if (vm.$refs.content) if (target != vm.$refs.content) vm.$refs.content.handleUpdate({srefIxBrlyVDpch: srefIxBrlyVDpch, dpcheng: dpcheng});
						}
					}

				}).catch(function (error) {
					console.log("SessBrly.handleRequest() error: " + error);
				});
			},

			handleUpload: function(obj) {
				var formData = new FormData()

				formData.append("file", obj.file, obj.file.name);

				axios.post(window.location.protocol + "//" + Brly.hostname() + ":" + Brly.appsrvport() + "/upload/" + obj.scrJref, formData).catch(function (error) {
					console.log("SessBrly.handleUpload() error: " + error);
				});
			},

			iterateNotify: function() {
				var vm = this;

				notify.get(this.scrJrefSess).then(function (response) {
					var iterate = true;

					const srefIxBrlyVDpch = Object.keys(response.data)[0];
					const dpcheng = response.data[srefIxBrlyVDpch];

					//console.log("SessBrly.iterateNotify() received " + srefIxBrlyVDpch);

					if (dpcheng.scrJref == vm.scrJrefSess) {
						if (srefIxBrlyVDpch == "DpchEngBrlyConfirm")
							if (!dpcheng.accepted) {
								vm.$emit('logout');
								iterate = false;
							}

					} else if (srefIxBrlyVDpch == "DpchEngBrlyAlert") vm.showAlert(dpcheng);
					else {
						var processed = false;
						const target = (dpcheng.scrJref == vm.scrJrefDlg) ? vm.$refs.dialog : (dpcheng.scrJref != vm.scrJrefCrdnav) ? vm.$refs.content : vm.$refs.CrdBrlyNav;
						processed = target.handleUpdate({srefIxBrlyVDpch: srefIxBrlyVDpch, dpcheng: dpcheng});
						if (!processed || (dpcheng.scrJref == vm.scrJrefCrd)) vm.$refs.CrdBrlyNav.handleUpdate({srefIxBrlyVDpch: srefIxBrlyVDpch, dpcheng: dpcheng});
					}

					if (iterate) vm.iterateNotify();

				}).catch(function (error) {
					console.log("SessBrly.iterateNotify() error: " + error);
				});
			}
		},

		data: () => ({
			content: "",

			srefCrd: "",
			scrJrefCrd: "",
			scrJrefDlg: "",

			alert: null,

			dialog: null
		})
	}
</script>
