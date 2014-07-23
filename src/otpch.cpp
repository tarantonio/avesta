



<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link rel="icon" type="image/vnd.microsoft.icon" href="https://ssl.gstatic.com/codesite/ph/images/phosting.ico">
 
 
 <script type="text/javascript">
 
 
 
 
 var codesite_token = "ABZ6GAdo1Bh6ClRbFmcCBcCXrhLIWxgjiQ:1406096620621";
 
 
 var CS_env = {"projectName": "avesta74", "projectHomeUrl": "/p/avesta74", "profileUrl": "/u/108692122734644646415/", "token": "ABZ6GAdo1Bh6ClRbFmcCBcCXrhLIWxgjiQ:1406096620621", "relativeBaseUrl": "", "domainName": null, "assetVersionPath": "https://ssl.gstatic.com/codesite/ph/13997016681179179006", "assetHostPath": "https://ssl.gstatic.com/codesite/ph", "loggedInUserEmail": "jose.guitian@coremain.com"};
 var _gaq = _gaq || [];
 _gaq.push(
 ['siteTracker._setAccount', 'UA-18071-1'],
 ['siteTracker._trackPageview']);
 
 _gaq.push(
 ['projectTracker._setAccount', 'UA-27551938-1'],
 ['projectTracker._trackPageview']);
 
 (function() {
 var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
 ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
 (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(ga);
 })();
 
 </script>
 
 
 <title>otpch.cpp - 
 avesta74 -
 
 
 A modified Open Tibia Server for the old tibia 7.4 - Google Project Hosting
 </title>
 <link type="text/css" rel="stylesheet" href="https://ssl.gstatic.com/codesite/ph/13997016681179179006/css/core.css">
 
 <link type="text/css" rel="stylesheet" href="https://ssl.gstatic.com/codesite/ph/13997016681179179006/css/ph_detail.css" >
 
 
 <link type="text/css" rel="stylesheet" href="https://ssl.gstatic.com/codesite/ph/13997016681179179006/css/d_sb.css" >
 
 
 
<!--[if IE]>
 <link type="text/css" rel="stylesheet" href="https://ssl.gstatic.com/codesite/ph/13997016681179179006/css/d_ie.css" >
<![endif]-->
 <style type="text/css">
 .menuIcon.off { background: no-repeat url(https://ssl.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -42px }
 .menuIcon.on { background: no-repeat url(https://ssl.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -28px }
 .menuIcon.down { background: no-repeat url(https://ssl.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 0; }
 
 
 
  tr.inline_comment {
 background: #fff;
 vertical-align: top;
 }
 div.draft, div.published {
 padding: .3em;
 border: 1px solid #999; 
 margin-bottom: .1em;
 font-family: arial, sans-serif;
 max-width: 60em;
 }
 div.draft {
 background: #ffa;
 } 
 div.published {
 background: #e5ecf9;
 }
 div.published .body, div.draft .body {
 padding: .5em .1em .1em .1em;
 max-width: 60em;
 white-space: pre-wrap;
 white-space: -moz-pre-wrap;
 white-space: -pre-wrap;
 white-space: -o-pre-wrap;
 word-wrap: break-word;
 font-size: 1em;
 }
 div.draft .actions {
 margin-left: 1em;
 font-size: 90%;
 }
 div.draft form {
 padding: .5em .5em .5em 0;
 }
 div.draft textarea, div.published textarea {
 width: 95%;
 height: 10em;
 font-family: arial, sans-serif;
 margin-bottom: .5em;
 }

 
 .nocursor, .nocursor td, .cursor_hidden, .cursor_hidden td {
 background-color: white;
 height: 2px;
 }
 .cursor, .cursor td {
 background-color: darkblue;
 height: 2px;
 display: '';
 }
 
 
.list {
 border: 1px solid white;
 border-bottom: 0;
}

 
 </style>
</head>
<body class="t4">
<script type="text/javascript">
 window.___gcfg = {lang: 'en'};
 (function() 
 {var po = document.createElement("script");
 po.type = "text/javascript"; po.async = true;po.src = "https://apis.google.com/js/plusone.js";
 var s = document.getElementsByTagName("script")[0];
 s.parentNode.insertBefore(po, s);
 })();
</script>
<div class="headbg">

 <div id="gaia">
 

 <span>
 
 
 
 <a href="#" id="multilogin-dropdown" onclick="return false;"
 ><u><b>jose.guitian@coremain.com</b></u> <small>&#9660;</small></a>
 
 
 | <a href="/u/108692122734644646415/" id="projects-dropdown" onclick="return false;"
 ><u>My favorites</u> <small>&#9660;</small></a>
 | <a href="/u/108692122734644646415/" onclick="_CS_click('/gb/ph/profile');"
 title="Profile, Updates, and Settings"
 ><u>Profile</u></a>
 | <a href="https://www.google.com/accounts/Logout?continue=https%3A%2F%2Fcode.google.com%2Fp%2Favesta74%2Fsource%2Fbrowse%2Ftrunk%2Fsrc%2Fotpch.cpp" 
 onclick="_CS_click('/gb/ph/signout');"
 ><u>Sign out</u></a>
 
 </span>

 </div>

 <div class="gbh" style="left: 0pt;"></div>
 <div class="gbh" style="right: 0pt;"></div>
 
 
 <div style="height: 1px"></div>
<!--[if lte IE 7]>
<div style="text-align:center;">
Your version of Internet Explorer is not supported. Try a browser that
contributes to open source, such as <a href="http://www.firefox.com">Firefox</a>,
<a href="http://www.google.com/chrome">Google Chrome</a>, or
<a href="http://code.google.com/chrome/chromeframe/">Google Chrome Frame</a>.
</div>
<![endif]-->



 <table style="padding:0px; margin: 0px 0px 10px 0px; width:100%" cellpadding="0" cellspacing="0"
 itemscope itemtype="http://schema.org/CreativeWork">
 <tr style="height: 58px;">
 
 
 
 <td id="plogo">
 <link itemprop="url" href="/p/avesta74">
 <a href="/p/avesta74/">
 
 <img src="https://ssl.gstatic.com/codesite/ph/images/defaultlogo.png" alt="Logo" itemprop="image">
 
 </a>
 </td>
 
 <td style="padding-left: 0.5em">
 
 <div id="pname">
 <a href="/p/avesta74/"><span itemprop="name">avesta74</span></a>
 </div>
 
 <div id="psum">
 <a id="project_summary_link"
 href="/p/avesta74/"><span itemprop="description">A modified Open Tibia Server for the old tibia 7.4</span></a>
 
 </div>
 
 
 </td>
 <td style="white-space:nowrap;text-align:right; vertical-align:bottom;">
 
 <form action="/hosting/search">
 <input size="30" name="q" value="" type="text">
 
 <input type="submit" name="projectsearch" value="Search projects" >
 </form>
 
 </tr>
 </table>

</div>

 
<div id="mt" class="gtb"> 
 <a href="/p/avesta74/" class="tab ">Project&nbsp;Home</a>
 
 
 
 
 <a href="/p/avesta74/downloads/list" class="tab ">Downloads</a>
 
 
 
 
 
 <a href="/p/avesta74/w/list" class="tab ">Wiki</a>
 
 
 
 
 
 <a href="/p/avesta74/issues/list"
 class="tab ">Issues</a>
 
 
 
 
 
 <a href="/p/avesta74/source/checkout"
 class="tab active">Source</a>
 
 
 
 
 
 
 
 
 <div class=gtbc></div>
</div>
<table cellspacing="0" cellpadding="0" width="100%" align="center" border="0" class="st">
 <tr>
 
 
 
 
 
 
 <td class="subt">
 <div class="st2">
 <div class="isf">
 
 


 <span class="inst1"><a href="/p/avesta74/source/checkout">Checkout</a></span> &nbsp;
 <span class="inst2"><a href="/p/avesta74/source/browse/">Browse</a></span> &nbsp;
 <span class="inst3"><a href="/p/avesta74/source/list">Changes</a></span> &nbsp;
 
 
 
 
 
 
 
 </form>
 <script type="text/javascript">
 
 function codesearchQuery(form) {
 var query = document.getElementById('q').value;
 if (query) { form.action += '%20' + query; }
 }
 </script>
 </div>
</div>

 </td>
 
 
 
 <td align="right" valign="top" class="bevel-right"></td>
 </tr>
</table>


<script type="text/javascript">
 var cancelBubble = false;
 function _go(url) { document.location = url; }
</script>
<div id="maincol"
 
>

 




<div class="expand">
<div id="colcontrol">
<style type="text/css">
 #file_flipper { white-space: nowrap; padding-right: 2em; }
 #file_flipper.hidden { display: none; }
 #file_flipper .pagelink { color: #0000CC; text-decoration: underline; }
 #file_flipper #visiblefiles { padding-left: 0.5em; padding-right: 0.5em; }
</style>
<table id="nav_and_rev" class="list"
 cellpadding="0" cellspacing="0" width="100%">
 <tr>
 
 <td nowrap="nowrap" class="src_crumbs src_nav" width="33%">
 <strong class="src_nav">Source path:&nbsp;</strong>
 <span id="crumb_root">
 
 <a href="/p/avesta74/source/browse/">svn</a>/&nbsp;</span>
 <span id="crumb_links" class="ifClosed"><a href="/p/avesta74/source/browse/trunk/">trunk</a><span class="sp">/&nbsp;</span><a href="/p/avesta74/source/browse/trunk/src/">src</a><span class="sp">/&nbsp;</span>otpch.cpp</span>
 
 


 </td>
 
 
 <td nowrap="nowrap" width="33%" align="center">
 <a href="/p/avesta74/source/browse/trunk/src/otpch.cpp?edit=1"
 ><img src="https://ssl.gstatic.com/codesite/ph/images/pencil-y14.png"
 class="edit_icon">Edit file</a>
 </td>
 
 
 <td nowrap="nowrap" width="33%" align="right">
 <table cellpadding="0" cellspacing="0" style="font-size: 100%"><tr>
 
 
 <td class="flipper">
 <ul class="leftside">
 
 <li><a href="/p/avesta74/source/browse/trunk/src/otpch.cpp?r=7" title="Previous">&lsaquo;r7</a></li>
 
 </ul>
 </td>
 
 <td class="flipper"><b>r102</b></td>
 
 </tr></table>
 </td> 
 </tr>
</table>

<div class="fc">
 
 
 
<style type="text/css">
.undermouse span {
 background-image: url(https://ssl.gstatic.com/codesite/ph/images/comments.gif); }
</style>
<table class="opened" id="review_comment_area"
><tr>
<td id="nums">
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
<pre><table width="100%" id="nums_table_0"><tr id="gr_svn102_1"

><td id="1"><a href="#1">1</a></td></tr
></table></pre>
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
</td>
<td id="lines">
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
<pre class="prettyprint lang-cpp"><table id="src_table_0"><tr
id=sl_svn102_1

><td class="source">#include &quot;otpch.h&quot;<br></td></tr
></table></pre>
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
</td>
</tr></table>

 
<script type="text/javascript">
 var lineNumUnderMouse = -1;
 
 function gutterOver(num) {
 gutterOut();
 var newTR = document.getElementById('gr_svn102_' + num);
 if (newTR) {
 newTR.className = 'undermouse';
 }
 lineNumUnderMouse = num;
 }
 function gutterOut() {
 if (lineNumUnderMouse != -1) {
 var oldTR = document.getElementById(
 'gr_svn102_' + lineNumUnderMouse);
 if (oldTR) {
 oldTR.className = '';
 }
 lineNumUnderMouse = -1;
 }
 }
 var numsGenState = {table_base_id: 'nums_table_'};
 var srcGenState = {table_base_id: 'src_table_'};
 var alignerRunning = false;
 var startOver = false;
 function setLineNumberHeights() {
 if (alignerRunning) {
 startOver = true;
 return;
 }
 numsGenState.chunk_id = 0;
 numsGenState.table = document.getElementById('nums_table_0');
 numsGenState.row_num = 0;
 if (!numsGenState.table) {
 return; // Silently exit if no file is present.
 }
 srcGenState.chunk_id = 0;
 srcGenState.table = document.getElementById('src_table_0');
 srcGenState.row_num = 0;
 alignerRunning = true;
 continueToSetLineNumberHeights();
 }
 function rowGenerator(genState) {
 if (genState.row_num < genState.table.rows.length) {
 var currentRow = genState.table.rows[genState.row_num];
 genState.row_num++;
 return currentRow;
 }
 var newTable = document.getElementById(
 genState.table_base_id + (genState.chunk_id + 1));
 if (newTable) {
 genState.chunk_id++;
 genState.row_num = 0;
 genState.table = newTable;
 return genState.table.rows[0];
 }
 return null;
 }
 var MAX_ROWS_PER_PASS = 1000;
 function continueToSetLineNumberHeights() {
 var rowsInThisPass = 0;
 var numRow = 1;
 var srcRow = 1;
 while (numRow && srcRow && rowsInThisPass < MAX_ROWS_PER_PASS) {
 numRow = rowGenerator(numsGenState);
 srcRow = rowGenerator(srcGenState);
 rowsInThisPass++;
 if (numRow && srcRow) {
 if (numRow.offsetHeight != srcRow.offsetHeight) {
 numRow.firstChild.style.height = srcRow.offsetHeight + 'px';
 }
 }
 }
 if (rowsInThisPass >= MAX_ROWS_PER_PASS) {
 setTimeout(continueToSetLineNumberHeights, 10);
 } else {
 alignerRunning = false;
 if (startOver) {
 startOver = false;
 setTimeout(setLineNumberHeights, 500);
 }
 }
 }
 function initLineNumberHeights() {
 // Do 2 complete passes, because there can be races
 // between this code and prettify.
 startOver = true;
 setTimeout(setLineNumberHeights, 250);
 window.onresize = setLineNumberHeights;
 }
 initLineNumberHeights();
</script>

 
 
 <div id="log">
 <div style="text-align:right">
 <a class="ifCollapse" href="#" onclick="_toggleMeta(this); return false">Show details</a>
 <a class="ifExpand" href="#" onclick="_toggleMeta(this); return false">Hide details</a>
 </div>
 <div class="ifExpand">
 
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="changelog">
 <p>Change log</p>
 <div>
 <a href="/p/avesta74/source/detail?spec=svn102&amp;r=52">r52</a>
 by r...@ymail.com
 on Jul 8, 2012
 &nbsp; <a href="/p/avesta74/source/diff?spec=svn102&r=52&amp;format=side&amp;path=/trunk/src/otpch.cpp&amp;old_path=/trunk/src/otpch.cpp&amp;old=7">Diff</a>
 </div>
 <pre>[No log message]</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/avesta74/source/detail?r=52&spec=svn102';
 var publish_url = '/p/avesta74/source/detail?r=52&spec=svn102#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/trunk/src/actions.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/actions.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/actions.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/actions.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/ban.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/ban.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/beds.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/beds.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/beds.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/beds.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/chat.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/chat.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/combat.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/combat.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/commands.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/commands.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/condition.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/condition.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/condition.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/condition.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/configmanager.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/configmanager.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/configmanager.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/configmanager.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/connection.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/connection.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/const.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/const.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/const74.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/const74.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/container.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/container.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/creature.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/creature.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/creature.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/creature.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/creatureevent.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/creatureevent.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/databasesqlite.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/databasesqlite.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/definitions.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/definitions.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/depot.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/depot.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/enums.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/enums.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/game.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/game.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/iomapserialize.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/iomapserialize.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/ioplayer.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/ioplayer.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/items.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/items.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/items.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/items.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/luascript.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/luascript.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/luascript.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/luascript.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/mailbox.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/mailbox.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/monster.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/monster.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/networkmessage.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/networkmessage.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/networkmessage.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/networkmessage.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/otpch.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/otpch.cpp?r\x3d52\x26spec\x3dsvn102');
 
 var selected_path = '/trunk/src/otpch.cpp';
 
 
 changed_paths.push('/trunk/src/otserv.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/otserv.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/party.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/party.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/player.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/player.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/player.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/player.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocol.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocol.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocol.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocol.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocol74.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocol74.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocol74.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocol74.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocolgame.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocolgame.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocolgame.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocolgame.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocollogin.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocollogin.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocollogin.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocollogin.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/raids.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/raids.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/resource.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/resource.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/rsa.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/rsa.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/rsa.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/rsa.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/server.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/server.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/spells.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/spells.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/spells.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/spells.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/talkaction.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/talkaction.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/tasks.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/tasks.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/thing.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/thing.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/tools.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/tools.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/trashholder.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/trashholder.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/vocation.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/vocation.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/vocation.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/vocation.h?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/weapons.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/weapons.cpp?r\x3d52\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/weapons.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/weapons.h?r\x3d52\x26spec\x3dsvn102');
 
 
 function getCurrentPageIndex() {
 for (var i = 0; i < changed_paths.length; i++) {
 if (selected_path == changed_paths[i]) {
 return i;
 }
 }
 }
 function getNextPage() {
 var i = getCurrentPageIndex();
 if (i < changed_paths.length - 1) {
 return changed_urls[i + 1];
 }
 return null;
 }
 function getPreviousPage() {
 var i = getCurrentPageIndex();
 if (i > 0) {
 return changed_urls[i - 1];
 }
 return null;
 }
 function gotoNextPage() {
 var page = getNextPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoPreviousPage() {
 var page = getPreviousPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoDetailPage() {
 window.location = detail_url;
 }
 function gotoPublishPage() {
 window.location = publish_url;
 }
</script>

 
 <style type="text/css">
 #review_nav {
 border-top: 3px solid white;
 padding-top: 6px;
 margin-top: 1em;
 }
 #review_nav td {
 vertical-align: middle;
 }
 #review_nav select {
 margin: .5em 0;
 }
 </style>
 <div id="review_nav">
 <table><tr><td>Go to:&nbsp;</td><td>
 <select name="files_in_rev" onchange="window.location=this.value">
 
 <option value="/p/avesta74/source/browse/trunk/src/actions.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/actions.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/actions.h?r=52&amp;spec=svn102"
 
 >/trunk/src/actions.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/ban.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/ban.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/beds.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/beds.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/beds.h?r=52&amp;spec=svn102"
 
 >/trunk/src/beds.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/chat.h?r=52&amp;spec=svn102"
 
 >/trunk/src/chat.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/combat.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/combat.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/commands.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/commands.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/condition.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/condition.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/condition.h?r=52&amp;spec=svn102"
 
 >/trunk/src/condition.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/configmanager.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/configmanager.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/configmanager.h?r=52&amp;spec=svn102"
 
 >/trunk/src/configmanager.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/connection.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/connection.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/const.h?r=52&amp;spec=svn102"
 
 >/trunk/src/const.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/const74.h?r=52&amp;spec=svn102"
 
 >/trunk/src/const74.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/container.h?r=52&amp;spec=svn102"
 
 >/trunk/src/container.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/creature.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/creature.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/creature.h?r=52&amp;spec=svn102"
 
 >/trunk/src/creature.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/creatureevent.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/creatureevent.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/databasesqlite.h?r=52&amp;spec=svn102"
 
 >/trunk/src/databasesqlite.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/definitions.h?r=52&amp;spec=svn102"
 
 >/trunk/src/definitions.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/depot.h?r=52&amp;spec=svn102"
 
 >/trunk/src/depot.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/enums.h?r=52&amp;spec=svn102"
 
 >/trunk/src/enums.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/game.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/game.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/iomapserialize.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/iomapserialize.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/ioplayer.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/ioplayer.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/items.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/items.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/items.h?r=52&amp;spec=svn102"
 
 >/trunk/src/items.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/luascript.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/luascript.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/luascript.h?r=52&amp;spec=svn102"
 
 >/trunk/src/luascript.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/mailbox.h?r=52&amp;spec=svn102"
 
 >/trunk/src/mailbox.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/monster.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/monster.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/networkmessage.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/networkmessage.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/networkmessage.h?r=52&amp;spec=svn102"
 
 >/trunk/src/networkmessage.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/otpch.cpp?r=52&amp;spec=svn102"
 selected="selected"
 >/trunk/src/otpch.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/otserv.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/otserv.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/party.h?r=52&amp;spec=svn102"
 
 >/trunk/src/party.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/player.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/player.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/player.h?r=52&amp;spec=svn102"
 
 >/trunk/src/player.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocol.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/protocol.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocol.h?r=52&amp;spec=svn102"
 
 >/trunk/src/protocol.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocol74.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/protocol74.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocol74.h?r=52&amp;spec=svn102"
 
 >/trunk/src/protocol74.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocolgame.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/protocolgame.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocolgame.h?r=52&amp;spec=svn102"
 
 >/trunk/src/protocolgame.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocollogin.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/protocollogin.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocollogin.h?r=52&amp;spec=svn102"
 
 >/trunk/src/protocollogin.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/raids.h?r=52&amp;spec=svn102"
 
 >/trunk/src/raids.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/resource.h?r=52&amp;spec=svn102"
 
 >/trunk/src/resource.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/rsa.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/rsa.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/rsa.h?r=52&amp;spec=svn102"
 
 >/trunk/src/rsa.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/server.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/server.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/spells.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/spells.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/spells.h?r=52&amp;spec=svn102"
 
 >/trunk/src/spells.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/talkaction.h?r=52&amp;spec=svn102"
 
 >/trunk/src/talkaction.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/tasks.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/tasks.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/thing.h?r=52&amp;spec=svn102"
 
 >/trunk/src/thing.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/tools.h?r=52&amp;spec=svn102"
 
 >/trunk/src/tools.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/trashholder.h?r=52&amp;spec=svn102"
 
 >/trunk/src/trashholder.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/vocation.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/vocation.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/vocation.h?r=52&amp;spec=svn102"
 
 >/trunk/src/vocation.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/weapons.cpp?r=52&amp;spec=svn102"
 
 >/trunk/src/weapons.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/weapons.h?r=52&amp;spec=svn102"
 
 >/trunk/src/weapons.h</option>
 
 </select>
 </td></tr></table>
 
 
 



 
 </div>
 
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="older_bubble">
 <p>Older revisions</p>
 
 
 <div class="closed" style="margin-bottom:3px;" >
 <a class="ifClosed" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/plus.gif" ></a>
 <a class="ifOpened" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/minus.gif" ></a>
 <a href="/p/avesta74/source/detail?spec=svn102&r=7">r7</a>
 by RSXQ66
 on Jul 23, 2010
 &nbsp; <a href="/p/avesta74/source/diff?spec=svn102&r=7&amp;format=side&amp;path=/trunk/src/otpch.cpp&amp;old_path=/trunk/src/otpch.cpp&amp;old=">Diff</a>
 <br>
 <pre class="ifOpened">[No log message]</pre>
 </div>
 
 
 <a href="/p/avesta74/source/list?path=/trunk/src/otpch.cpp&start=52">All revisions of this file</a>
 </div>
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="fileinfo_bubble">
 <p>File info</p>
 
 <div>Size: 20 bytes,
 1 line</div>
 
 <div><a href="//avesta74.googlecode.com/svn/trunk/src/otpch.cpp">View raw file</a></div>
 </div>
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 </div>
 </div>


</div>

</div>
</div>

<script src="https://ssl.gstatic.com/codesite/ph/13997016681179179006/js/prettify/prettify.js"></script>
<script type="text/javascript">prettyPrint();</script>


<script src="https://ssl.gstatic.com/codesite/ph/13997016681179179006/js/source_file_scripts.js"></script>

 <script type="text/javascript" src="https://ssl.gstatic.com/codesite/ph/13997016681179179006/js/kibbles.js"></script>
 <script type="text/javascript">
 var lastStop = null;
 var initialized = false;
 
 function updateCursor(next, prev) {
 if (prev && prev.element) {
 prev.element.className = 'cursor_stop cursor_hidden';
 }
 if (next && next.element) {
 next.element.className = 'cursor_stop cursor';
 lastStop = next.index;
 }
 }
 
 function pubRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initialized) {
 reloadCursors();
 }
 }
 
 function draftRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initialized) {
 reloadCursors();
 }
 }
 
 function draftDestroyed(data) {
 updateCursorForCell(data.cellId, 'nocursor');
 if (initialized) {
 reloadCursors();
 }
 }
 function reloadCursors() {
 kibbles.skipper.reset();
 loadCursors();
 if (lastStop != null) {
 kibbles.skipper.setCurrentStop(lastStop);
 }
 }
 // possibly the simplest way to insert any newly added comments
 // is to update the class of the corresponding cursor row,
 // then refresh the entire list of rows.
 function updateCursorForCell(cellId, className) {
 var cell = document.getElementById(cellId);
 // we have to go two rows back to find the cursor location
 var row = getPreviousElement(cell.parentNode);
 row.className = className;
 }
 // returns the previous element, ignores text nodes.
 function getPreviousElement(e) {
 var element = e.previousSibling;
 if (element.nodeType == 3) {
 element = element.previousSibling;
 }
 if (element && element.tagName) {
 return element;
 }
 }
 function loadCursors() {
 // register our elements with skipper
 var elements = CR_getElements('*', 'cursor_stop');
 var len = elements.length;
 for (var i = 0; i < len; i++) {
 var element = elements[i]; 
 element.className = 'cursor_stop cursor_hidden';
 kibbles.skipper.append(element);
 }
 }
 function toggleComments() {
 CR_toggleCommentDisplay();
 reloadCursors();
 }
 function keysOnLoadHandler() {
 // setup skipper
 kibbles.skipper.addStopListener(
 kibbles.skipper.LISTENER_TYPE.PRE, updateCursor);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_top', 50);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_bottom', 100);
 // Register our keys
 kibbles.skipper.addFwdKey("n");
 kibbles.skipper.addRevKey("p");
 kibbles.keys.addKeyPressListener(
 'u', function() { window.location = detail_url; });
 kibbles.keys.addKeyPressListener(
 'r', function() { window.location = detail_url + '#publish'; });
 
 kibbles.keys.addKeyPressListener('j', gotoNextPage);
 kibbles.keys.addKeyPressListener('k', gotoPreviousPage);
 
 
 }
 </script>
<script src="https://ssl.gstatic.com/codesite/ph/13997016681179179006/js/code_review_scripts.js"></script>
<script type="text/javascript">
 function showPublishInstructions() {
 var element = document.getElementById('review_instr');
 if (element) {
 element.className = 'opened';
 }
 }
 var codereviews;
 function revsOnLoadHandler() {
 // register our source container with the commenting code
 var paths = {'svn102': '/trunk/src/otpch.cpp'}
 codereviews = CR_controller.setup(
 {"projectName": "avesta74", "projectHomeUrl": "/p/avesta74", "profileUrl": "/u/108692122734644646415/", "token": "ABZ6GAdo1Bh6ClRbFmcCBcCXrhLIWxgjiQ:1406096620621", "relativeBaseUrl": "", "domainName": null, "assetVersionPath": "https://ssl.gstatic.com/codesite/ph/13997016681179179006", "assetHostPath": "https://ssl.gstatic.com/codesite/ph", "loggedInUserEmail": "jose.guitian@coremain.com"}, '', 'svn102', paths,
 CR_BrowseIntegrationFactory);
 
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_DRAFT_PLATE, showPublishInstructions);
 
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_PUB_PLATE, pubRevealed);
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_DRAFT_PLATE, draftRevealed);
 codereviews.registerActivityListener(CR_ActivityType.DISCARD_DRAFT_COMMENT, draftDestroyed);
 
 
 
 
 
 
 
 var initialized = true;
 reloadCursors();
 }
 window.onload = function() {keysOnLoadHandler(); revsOnLoadHandler();};

</script>
<script type="text/javascript" src="https://ssl.gstatic.com/codesite/ph/13997016681179179006/js/dit_scripts.js"></script>

 
 
 
 <script type="text/javascript" src="https://ssl.gstatic.com/codesite/ph/13997016681179179006/js/ph_core.js"></script>
 
 
 
 
</div> 

<div id="footer" dir="ltr">
 <div class="text">
 <a href="/projecthosting/terms.html">Terms</a> -
 <a href="http://www.google.com/privacy.html">Privacy</a> -
 <a href="/p/support/">Project Hosting Help</a>
 </div>
</div>
 <div class="hostedBy" style="margin-top: -20px;">
 <span style="vertical-align: top;">Powered by <a href="http://code.google.com/projecthosting/">Google Project Hosting</a></span>
 </div>

 
 


 
 </body>
</html>

