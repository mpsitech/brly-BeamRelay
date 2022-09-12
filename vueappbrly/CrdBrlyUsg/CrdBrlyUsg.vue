<template>
	<v-container v-if="initdone">
		<PnlBrlyUsgList
			v-on:request="handleRequest"
			ref="PnlBrlyUsgList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlBrlyUsgRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlBrlyUsgRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Brly from '../../scripts/Brly';

	/*
	*/
	import PnlBrlyUsgList from './PnlBrlyUsgList';
	import PnlBrlyUsgRec from './PnlBrlyUsgRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdBrlyUsg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlBrlyUsgList,
			PnlBrlyUsgRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdBrlyUsg.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfBrlyUsg) this.continf = dpcheng.ContInfBrlyUsg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppBrlyUsg) this.statapp = dpcheng.StatAppBrlyUsg;
				if (dpcheng.StatShrBrlyUsg) this.statshr = dpcheng.StatShrBrlyUsg;
				if (dpcheng.TagBrlyUsg) {
					Brly.unescapeBlock(dpcheng.TagBrlyUsg);
					this.tag = dpcheng.TagBrlyUsg;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlBrlyUsgList.handleReply(obj);
					else this.$refs.PnlBrlyUsgRec.handleReply(obj);
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
					if (obj.srefIxBrlyVDpch == "DpchEngBrlyUsgData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlBrlyUsgList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlBrlyUsgRec.handleUpdate(obj);
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
