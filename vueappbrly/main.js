import Vue from 'vue'
import axios from 'axios'
import VueAxios from 'vue-axios'
import AppBrly from './AppBrly.vue'
import vuetify from './plugins/vuetify'

Vue.config.productionTip = false

Vue.use(VueAxios, axios)

new Vue({
	vuetify,
	render: h => h(AppBrly)
}).$mount("#app")
