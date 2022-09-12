<template>
	<v-container v-if="initdone">
		<PnlBrlyRegList
			v-on:request="handleRequest"
			ref="PnlBrlyRegList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyRegRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyRegRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyRegList from './PnlBrlyRegList';
	import PnlBrlyRegRec from './PnlBrlyRegRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyReg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyRegList,
			PnlBrlyRegRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyReg.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfBrlyReg) this.continf = dpcheng.ContInfBrlyReg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyReg) this.statapp = dpcheng.StatAppBrlyReg;
				if (dpcheng.StatShrBrlyReg) this.statshr = dpcheng.StatShrBrlyReg;
				if (dpcheng.TagBrlyReg) {
					Brly.unescapeBlock(dpcheng.TagBrlyReg);
					this.tag = dpcheng.TagBrlyReg;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyRegList.handleReply(obj);
					else this.$refs.PnlBrlyRegRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyRegData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyRegList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyRegRec.handleUpdate(obj);
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
