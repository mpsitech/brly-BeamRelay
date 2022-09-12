<template>
	<v-container v-if="initdone">
		<PnlBrlyLocList
			v-on:request="handleRequest"
			ref="PnlBrlyLocList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyLocRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyLocRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyLocList from './PnlBrlyLocList';
	import PnlBrlyLocRec from './PnlBrlyLocRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyLoc',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyLocList,
			PnlBrlyLocRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyLoc.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfBrlyLoc) this.continf = dpcheng.ContInfBrlyLoc;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyLoc) this.statapp = dpcheng.StatAppBrlyLoc;
				if (dpcheng.StatShrBrlyLoc) this.statshr = dpcheng.StatShrBrlyLoc;
				if (dpcheng.TagBrlyLoc) {
					Brly.unescapeBlock(dpcheng.TagBrlyLoc);
					this.tag = dpcheng.TagBrlyLoc;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyLocList.handleReply(obj);
					else this.$refs.PnlBrlyLocRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyLocData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyLocList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyLocRec.handleUpdate(obj);
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
