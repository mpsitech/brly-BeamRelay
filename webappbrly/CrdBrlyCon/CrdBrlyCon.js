function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppBrlyCon", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppBrlyCon", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppBrlyCon", "initdoneHeadbar") == "true");
	var initdoneList = (retrieveSi(srcdoc, "StatAppBrlyCon", "initdoneList") == "true");
	var initdoneRec = (retrieveSi(srcdoc, "StatAppBrlyCon", "initdoneRec") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlBrlyConHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdoneList) {
		doc.getElementById("List").src = "./PnlBrlyConList.html?scrJref=" + scrJrefList;
	} else if (!initdoneRec) {
		doc.getElementById("Rec").src = "./PnlBrlyConRec.html?scrJref=" + scrJrefRec;
	} else {
		doc.initdone = true;
		window.onfocus = resumeNotify;

		refresh();

		restartNotify();
	};
};

function setPnlAvail(short, avail) {
	var oldAvail = (doc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) {
			doc.getElementById("spc" + short).setAttribute("class", "show");
			doc.getElementById("tr" + short).setAttribute("class", "show");
		} else {
			doc.getElementById(short).contentWindow.minimize();
			doc.getElementById("spc" + short).setAttribute("class", "hide");
			doc.getElementById("tr" + short).setAttribute("class", "hide");
		};
	};
};

function getHeight() {
	var height = 25;

	height += 10 + parseInt(doc.getElementById("tdList").getAttribute("height")) + 8;
	height += 10 + parseInt(doc.getElementById("tdRec").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppBrlyCon", "shortMenu");

	if (doc.getElementById("divMenu")) {
		if (shortMenu == short)
			hideMenu(shortMenu);
		else {
			hideMenu(shortMenu);
			showMenu(short, left, width, height);
		};

	} else {
		showMenu(short, left, width, height);
	};
};

function showMenu(short, left, width, height) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppBrlyCon", "shortMenu", short);
	setSi(srcdoc, "StatAppBrlyCon", "widthMenu", "" + (width-3));

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuappact");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menuact");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menulineact");

	var body = doc.getElementById("body");
	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "menu");
	mydiv.setAttribute("id", "divMenu");
	mydiv.setAttribute("style", "left:" + left + "px;");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Menu");
	myif.setAttribute("src", "./Men" + short + ".html");
	myif.setAttribute("width", "" + width);
	myif.setAttribute("height", "" + height);
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideMenu(short) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppBrlyCon", "shortMenu", "");

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppBrlyCon", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagBrlyCon", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagBrlyCon", "MrlAppHlp"));
};

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrBrlyCon", "MspCrd1Avail") == "true");
	MitCrdNewAvail = (retrieveSi(srcdoc, "StatShrBrlyCon", "MitCrdNewAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppBrlyCon", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxCrdCon"), retrieveCi(srcdoc, "ContInfBrlyCon", "MtxCrdCon"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdNew"), retrieveTi(srcdoc, "TagBrlyCon", "MitCrdNew"));

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdNew", MitCrdNewAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function setMitMspAvail(short, avail, dh) {
	var mendoc = doc.getElementById("Menu").contentDocument;

	if (!avail) mendoc.getElementById("tr" + short).setAttribute("class", "hide");

	if (avail) return 0;
	else return dh;
};

function setMitActive(short, active) {
	var mendoc = doc.getElementById("Menu").contentDocument;
	var mit = mendoc.getElementById(short);

	if (active) {
		mit.setAttribute("class", "item");
		mit.setAttribute("onclick", "handle" + short + "Click()");
	} else {
		mit.setAttribute("class", "itemdis");
		mit.setAttribute("onclick", "");
	};
};

// --- detached panel functionality
function detachPnl(sref, _scrJref) {
	if ((scrJrefPnld != "") && (scrJrefPnld != _scrJref)) attachPnl();

	scrJrefPnld = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divPnldshld");
	mydiv.setAttribute("class", "pnldshld");
	mydiv.setAttribute("style", "height:" + (getHeight()-35) + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "pnld");
	mydiv.setAttribute("id", "divPnld");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Pnld");
	myif.setAttribute("src", "./" + sref + "_d.html?scrJref=" + _scrJref);
	myif.setAttribute("width", "891"); /// PRELIMINARY
	myif.setAttribute("height", "586");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function maximizePnl() {
	/// TBD
};

function attachPnl() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divPnldshld"));
	body.removeChild(doc.getElementById("divPnld"));

	doc.getElementById("Rec").contentWindow.reinitPnl(scrJrefPnld);

	scrJrefPnld = "";
};

// --- dialog functionality
function showDlg(sref, _scrJref)  {
	if ((scrJrefDlg != "") && (scrJrefDlg != _scrJref)) hideDlg();

	scrJrefDlg = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divDlgshld");
	mydiv.setAttribute("class", "dlgshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "dlg");
	mydiv.setAttribute("id", "divDlg");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Dlg");
	myif.setAttribute("src", "./" + sref + ".html?scrJref=" + _scrJref);
	myif.setAttribute("width", "691");
	if ((sref == "DlgBrlyConNew")) myif.setAttribute("height", "585");
	else myif.setAttribute("height", "555");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideDlg() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divDlgshld"));
	body.removeChild(doc.getElementById("divDlg"));

	scrJrefDlg = "";
};

// --- alert functionality
function showAlr(_scrJref, blkcontinf, blkfeedfmcb)  {
	// update information
	scrJrefAlr = _scrJref;

	replaceSrcblock(blkcontinf, "ContInfBrlyAlert", srcdoc);
	replaceSrcblock(blkfeedfmcb, "FeedFMcbAlert", srcdoc);

	// show alert
	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divAlrshld");
	mydiv.setAttribute("class", "alrshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "alr");
	mydiv.setAttribute("id", "divAlr");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Alr");
	myif.setAttribute("src", "../iframe/alr.xml");
	myif.setAttribute("width", "501");
	myif.setAttribute("height", "60");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideAlr(numFMcb) {
	var str = serializeDpchAppAlert(scrJrefAlr, numFMcb);
	sendReq(str, doc, handleDpchAppDoReply);

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divAlrshld"));
	body.removeChild(doc.getElementById("divAlr"));

	scrJrefAlr = "";
};

function initAlr() {
	var alrdoc = doc.getElementById("Alr").contentDocument;

	var height = 30+2+3+25;

	setTextContent(alrdoc, alrdoc.getElementById("TxtCpt"), retrieveCi(srcdoc, "ContInfBrlyAlert", "TxtCpt"));

	height += fillAlrTxtMsgFromCont(alrdoc, srcdoc, "ContInfBrlyAlert");

	doc.getElementById("Alr").setAttribute("height", "" + height);

	fillAlrMcbFromFeed(alrdoc, srcdoc, "FeedFMcbAlert");
};

// --- expand state management
function changeHeight(pnlshort, height) {
	var divPnldshld = doc.getElementById("divPnldshld");
	var divDlgshld = doc.getElementById("divDlgshld");
	var divAlrshld = doc.getElementById("divAlrshld");

	if (pnlshort == "List") {
		doc.getElementById("tdList").setAttribute("height", "" + height);
		doc.getElementById("List").setAttribute("height", "" + height);
	} else if (pnlshort == "Rec") {
		doc.getElementById("tdRec").setAttribute("height", "" + height);
		doc.getElementById("Rec").setAttribute("height", "" + height);
	};

	if (divPnldshld) divPnldshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divDlgshld) divDlgshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divAlrshld) divAlrshld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgnew = retrieveSi(srcdoc, "StatShrBrlyCon", "scrJrefDlgnew");

	if (scrJrefDlgnew != "") {
		if (scrJrefDlg != scrJrefDlgnew) showDlg("DlgBrlyConNew", scrJrefDlgnew);
	} else if (scrJrefDlg != "") hideDlg();

	doc.title = retrieveCi(srcdoc, "ContInfBrlyCon", "MtxCrdCon") + " - BeamRelay v0.2.15";
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleUnload() {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyConDo", scrJref, "close");
	sendReq(str, doc, null, true);
};

function handleMitClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyConDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, consref) {
	window.open(retrieveCi(srcdoc, "ContInfBrlyCon", consref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyConData", "ContInfBrlyCon", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyConData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngBrlyConData", "StatAppBrlyCon", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyConData", "StatShrBrlyCon", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyConData", "TagBrlyCon", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEngSub(_scrJref, dom, dpch) {
	if (_scrJref == scrJrefPnld) {
		doc.getElementById("Pnld").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefDlg) {
		doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefList) {
		doc.getElementById("List").contentWindow.handleDpchEng(dom, dpch);

	} else {
		// scrJrefRec or scrJref of one of its sub-panels
		doc.getElementById("Rec").contentWindow.handleDpchEng(dom, dpch);
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngBrlyConData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrBrlyCon", "scrJrefHeadbar");
				scrJrefList = retrieveSi(srcdoc, "StatShrBrlyCon", "scrJrefList");
				scrJrefRec = retrieveSi(srcdoc, "StatShrBrlyCon", "scrJrefRec");

				scrJrefPnld = "";

				scrJrefDlg = "";

				scrJrefAlr = "";

				// load sub-panels one by one
				checkInitdone();
			};
		};
	};
};

function handleDpchAppDoReply() {
	var _scrJref;

	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//brly:*");

		if (blk) {
			_scrJref = retrieveValue(dom, "//brly:*/brly:scrJref");

			if (_scrJref != "") {
				if (_scrJref == scrJref) {
					if (blk.nodeName == "DpchEngBrlyConfirm") {
						// do nothing

					} else if (blk.nodeName == "DpchEngBrlyAlert") {
						// show alert with new content
						showAlr(retrieveValue(dom, "//brly:DpchEngBrlyAlert/brly:scrJref"),
								retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:ContInfBrlyAlert"),
								retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:FeedFMcbAlert"));

					} else if (blk.nodeName == "DpchEngBrlyConData") {
						mergeDpchEngData(dom);
						refresh();
					};

				} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
			};

			restartNotify();
		};
	};
};

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

	window.open("about:blank", "_self");
};

function restartNotify() {
	var srefIxBrlyVReqitmode = retrieveSi(srcdoc, "StatAppBrlyCon", "srefIxBrlyVReqitmode");

	if (srefIxBrlyVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxBrlyVReqitmode = "notify";
		setSi(srcdoc, "StatAppBrlyCon", "srefIxBrlyVReqitmode", srefIxBrlyVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxBrlyVReqitmode = retrieveSi(srcdoc, "StatAppBrlyCon", "srefIxBrlyVReqitmode");

	if (srefIxBrlyVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		var str = serializeDpchApp("DpchAppBrlyResume", scrJref);
		sendReq(str, doc, handleDpchAppResumeReply);
	};
};

function handleDpchAppResumeReply() {
	var dom, blk;

	if ((doc.req.readyState == 4) && (doc.req.status == 404)) {
		terminate();

	} else if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");

		if (blk) if (blk.nodeName == "DpchEngBrlyAck") restartNotify();
	};
};

function iteratePoll() {
	iterateReqit();
};

function iterateReqit(ev) {
	var accepted, _scrJref, mask;

	var news = false;
	var iterate = true;

	var srefIxBrlyVReqitmode = retrieveSi(srcdoc, "StatAppBrlyCon", "srefIxBrlyVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppBrlyCon", "latency"));

	if (doc.reqit && ev) {
		if (doc.reqit.readyState != 4) {
			iterate = false;

		} else if ((doc.reqit.readyState == 4) && (doc.reqit.status == 404)) {
			iterate = false;

			terminate();

		} else if (doc.reqit.readyState == 4) {
			dom = doc.reqit.responseXML;

			// check dispatch type
			blk = retrieveBlock(dom, "//brly:*");

			if (blk) {
				if (blk.nodeName == "DpchEngBrlyAck") {
					// no news
					// alert("no news");

				} else if (blk.nodeName == "DpchEngBrlySuspend") {
					// change to "poll" mode
					news = true;

					srefIxBrlyVReqitmode = "poll";
					setSi(srcdoc, "StatAppBrlyCon", "srefIxBrlyVReqitmode", srefIxBrlyVReqitmode);

				} else {
					// request with content
					news = true;

					_scrJref = retrieveValue(dom, "//brly:*/brly:scrJref");

					if (blk.nodeName == "DpchEngBrlyAlert") {
						// card-based treatment even for scrJref corresponding to panel / dialog
						showAlr(retrieveValue(dom, "//brly:DpchEngBrlyAlert/brly:scrJref"),
								retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:ContInfBrlyAlert"),
								retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:FeedFMcbAlert"));

					} else if (_scrJref != "") {
						if (_scrJref == scrJref) {
							if (blk.nodeName == "DpchEngBrlyConfirm") {
								accepted = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:accepted");

								if (accepted == "false") {
									// arrives on card close
									iterate = false;
									terminate();
								};

							} else if (blk.nodeName == "DpchEngBrlyConData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
					};
				};
			};
		};
	};

	if ((srefIxBrlyVReqitmode == "notify") && iterate) {
		// send notify request
		if (!doc.reqit) doc.reqit = new XMLHttpRequest();
		doc.reqit.onreadystatechange = iterateReqit;
		doc.reqit.open("GET", "/notify/" + scrJref, true);
		doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		doc.reqit.send("");

	} else if ((srefIxBrlyVReqitmode == "poll") && iterate) {
		if (!ev || (news && ev)) {
			// send poll request
			if (!doc.reqit) doc.reqit = new XMLHttpRequest();
			doc.reqit.onreadystatechange = iterateReqit;
			doc.reqit.open("GET", "/poll/" + scrJref, true);
			doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			doc.reqit.send("");

		} else {
			// wait
			doc.timeout = setTimeout(iteratePoll, latency*1000);
		};
	};
};
