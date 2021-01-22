// --- view initialization
function getMenAvail(short) {
	return(retrieveSi(srcdoc, "StatShrBrlyNavHeadbar", "Men" + short + "Avail") == "true");
};

function getMenCptwidth(short) {
	return(parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "Men" + short + "Cptwidth")));
};

function getMenLeft(short) {
	var left = 3;

	if (short == "App") return(left);
	left += getMenCptwidth("App") + 1;

	if (short == "Ses") return(left);
	left += getMenCptwidth("Ses") + 1;

	if (short == "Crd") return(left);
	if (getMenAvail("Crd")) left += getMenCptwidth("Crd") + 1;

	return left;
};

function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var w, wFill;
	wFill = 995;

	w = getMenCptwidth("App"); contdoc.getElementById("colMenApp").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenApp"), "\\u00a0" + retrieveTi(srcdoc, "TagBrlyNavHeadbar", "MenApp") + "\\u00a0");
	w = getMenCptwidth("Ses"); contdoc.getElementById("colMenSes").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenSes"), "\\u00a0" + retrieveTi(srcdoc, "TagBrlyNavHeadbar", "MenSes") + "\\u00a0");
	w = getMenCptwidth("Crd"); contdoc.getElementById("colMenCrd").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagBrlyNavHeadbar", "MenCrd") + "\\u00a0");
	if (!getMenAvail("Crd")) contdoc.getElementById("tdMenCrd").setAttribute("class", "hide");

	contdoc.getElementById("colFill").setAttribute("width", "" + wFill);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Headbar_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleMenAppClick() {
	getCrdwnd().toggleMenu("App", getMenLeft("App"), parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenAppWidth")), 63);
};

function handleMenSesClick() {
	getCrdwnd().toggleMenu("Ses", getMenLeft("Ses"), parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenSesWidth")), 103);
};

function handleMenCrdClick() {
	getCrdwnd().toggleMenu("Crd", getMenLeft("Crd"), parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenCrdWidth")), 284);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyNavHeadbarData", "StatShrBrlyNavHeadbar", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyNavHeadbarData", "StgInfBrlyNavHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngBrlyNavHeadbarData", "TagBrlyNavHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngBrlyNavHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};
