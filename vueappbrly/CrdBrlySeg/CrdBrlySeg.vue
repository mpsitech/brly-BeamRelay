<template>
	<v-container v-if="initdone">
		<PnlBrlySegList
			v-on:request="handleRequest"
			ref="PnlBrlySegList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlySegRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlySegRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlySegList from './PnlBrlySegList';
	import PnlBrlySegRec from './PnlBrlySegRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlySeg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlySegList,
			PnlBrlySegRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlySeg.mounted() with scrJref = " + this.scrJref);

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

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfBrlySeg) this.continf = dpcheng.ContInfBrlySeg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlySeg) this.statapp = dpcheng.StatAppBrlySeg;
				if (dpcheng.StatShrBrlySeg) this.statshr = dpcheng.StatShrBrlySeg;
				if (dpcheng.TagBrlySeg) {
					Brly.unescapeBlock(dpcheng.TagBrlySeg);
					this.tag = dpcheng.TagBrlySeg;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlySegList.handleReply(obj);
					else this.$refs.PnlBrlySegRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxBrlyVDpch == "DpchEngBrlySegData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlySegList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlySegRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxBrlyVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

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
