<template>
	<v-app>
		<v-main>
			<!-- srefIxVSge prop for CrdBrlyStart, others for SessBrly -->
			<component
				v-bind:is="content"
				v-on:login="handleLogin"
				v-on:logout="handleLogout"
				ref="content"
				:srefIxVSge_initial=srefIxVSge
				:scrJrefSess=scrJrefSess
				:scrJrefCrdnav=scrJrefCrdnav
				:srefCrd_initial=srefCrd
				:scrJrefCrd_initial=scrJrefCrd
			/>
		</v-main>
	</v-app>
</template>

<script>
	import Brly from './scripts/Brly';

	import CrdBrlyStart from './components/CrdBrlyStart/CrdBrlyStart';
	import SessBrly from './components/SessBrly';

	export default {
		name: 'AppBrly',

		components: {
			CrdBrlyStart,
			SessBrly
		},

		beforeMount() {
			document.title = Brly.title + " v" + Brly.version;

			// possible keys: scrJrefSess, scrJrefCrdnav, srefCrd, scrJrefCrd
			const params = new URLSearchParams(window.location.search);
			//params.forEach(function(value, key) {console.log(key + ": " + value)});

			this.childNotParent = params.has("scrJrefSess");

			if (!this.childNotParent) this.content = "CrdBrlyStart";
			else {
				this.scrJrefSess = params.get("scrJrefSess");
				this.scrJrefCrdnav = params.get("scrJrefCrdnav");

				this.srefCrd = params.get("srefCrd");
				this.scrJrefCrd = params.get("scrJrefCrd");

				this.content = "SessBrly";
			}
		},

		methods: {
			handleLogin(obj) {
				//console.log("AppBrly.handleLogin() received login event with scrJrefSess = " + scrJrefSess);

				this.scrJrefSess = obj.scrJrefSess;
				this.scrJrefCrdnav = obj.scrJrefCrdnav;

				this.srefCrd = "";
				this.scrJrefCrd = "";

				this.content = "SessBrly"
			},

			handleLogout() {
				if (!this.childNotParent) {
					this.srefIxVSge = "term";

					this.scrJrefSess = "";
					this.scrJrefCrdnav = "";

					this.srefCrd = "";
					this.scrJrefCrd = "";

					this.content = "CrdBrlyStart"

				} else window.open("about:blank", "_self");
			}
		},

		data: () => ({
			childNotParent: false,	

			content: "",

			srefIxVSge: "idle",

			scrJrefSess: "",
			scrJrefCrdnav: "",

			srefCrd: "",
			scrJrefCrd: ""
		})
	};
</script>
