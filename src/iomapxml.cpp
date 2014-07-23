



<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link rel="icon" type="image/vnd.microsoft.icon" href="https://ssl.gstatic.com/codesite/ph/images/phosting.ico">
 
 
 <script type="text/javascript">
 
 
 
 
 var codesite_token = "ABZ6GAcSi0iA6SDok5j5EkF6eJ_hIrM9FQ:1406096534816";
 
 
 var CS_env = {"assetVersionPath": "https://ssl.gstatic.com/codesite/ph/13997016681179179006", "projectName": "avesta74", "projectHomeUrl": "/p/avesta74", "relativeBaseUrl": "", "loggedInUserEmail": "jose.guitian@coremain.com", "profileUrl": "/u/108692122734644646415/", "token": "ABZ6GAcSi0iA6SDok5j5EkF6eJ_hIrM9FQ:1406096534816", "domainName": null, "assetHostPath": "https://ssl.gstatic.com/codesite/ph"};
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
 
 
 <title>iomapxml.cpp - 
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
 | <a href="https://www.google.com/accounts/Logout?continue=https%3A%2F%2Fcode.google.com%2Fp%2Favesta74%2Fsource%2Fbrowse%2Ftrunk%2Fsrc%2Fiomapxml.cpp" 
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
 <span id="crumb_links" class="ifClosed"><a href="/p/avesta74/source/browse/trunk/">trunk</a><span class="sp">/&nbsp;</span><a href="/p/avesta74/source/browse/trunk/src/">src</a><span class="sp">/&nbsp;</span>iomapxml.cpp</span>
 
 


 </td>
 
 
 <td nowrap="nowrap" width="33%" align="center">
 <a href="/p/avesta74/source/browse/trunk/src/iomapxml.cpp?edit=1"
 ><img src="https://ssl.gstatic.com/codesite/ph/images/pencil-y14.png"
 class="edit_icon">Edit file</a>
 </td>
 
 
 <td nowrap="nowrap" width="33%" align="right">
 <table cellpadding="0" cellspacing="0" style="font-size: 100%"><tr>
 
 
 <td class="flipper">
 <ul class="leftside">
 
 <li><a href="/p/avesta74/source/browse/trunk/src/iomapxml.cpp?r=7" title="Previous">&lsaquo;r7</a></li>
 
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
><tr id="gr_svn102_2"

><td id="2"><a href="#2">2</a></td></tr
><tr id="gr_svn102_3"

><td id="3"><a href="#3">3</a></td></tr
><tr id="gr_svn102_4"

><td id="4"><a href="#4">4</a></td></tr
><tr id="gr_svn102_5"

><td id="5"><a href="#5">5</a></td></tr
><tr id="gr_svn102_6"

><td id="6"><a href="#6">6</a></td></tr
><tr id="gr_svn102_7"

><td id="7"><a href="#7">7</a></td></tr
><tr id="gr_svn102_8"

><td id="8"><a href="#8">8</a></td></tr
><tr id="gr_svn102_9"

><td id="9"><a href="#9">9</a></td></tr
><tr id="gr_svn102_10"

><td id="10"><a href="#10">10</a></td></tr
><tr id="gr_svn102_11"

><td id="11"><a href="#11">11</a></td></tr
><tr id="gr_svn102_12"

><td id="12"><a href="#12">12</a></td></tr
><tr id="gr_svn102_13"

><td id="13"><a href="#13">13</a></td></tr
><tr id="gr_svn102_14"

><td id="14"><a href="#14">14</a></td></tr
><tr id="gr_svn102_15"

><td id="15"><a href="#15">15</a></td></tr
><tr id="gr_svn102_16"

><td id="16"><a href="#16">16</a></td></tr
><tr id="gr_svn102_17"

><td id="17"><a href="#17">17</a></td></tr
><tr id="gr_svn102_18"

><td id="18"><a href="#18">18</a></td></tr
><tr id="gr_svn102_19"

><td id="19"><a href="#19">19</a></td></tr
><tr id="gr_svn102_20"

><td id="20"><a href="#20">20</a></td></tr
><tr id="gr_svn102_21"

><td id="21"><a href="#21">21</a></td></tr
><tr id="gr_svn102_22"

><td id="22"><a href="#22">22</a></td></tr
><tr id="gr_svn102_23"

><td id="23"><a href="#23">23</a></td></tr
><tr id="gr_svn102_24"

><td id="24"><a href="#24">24</a></td></tr
><tr id="gr_svn102_25"

><td id="25"><a href="#25">25</a></td></tr
><tr id="gr_svn102_26"

><td id="26"><a href="#26">26</a></td></tr
><tr id="gr_svn102_27"

><td id="27"><a href="#27">27</a></td></tr
><tr id="gr_svn102_28"

><td id="28"><a href="#28">28</a></td></tr
><tr id="gr_svn102_29"

><td id="29"><a href="#29">29</a></td></tr
><tr id="gr_svn102_30"

><td id="30"><a href="#30">30</a></td></tr
><tr id="gr_svn102_31"

><td id="31"><a href="#31">31</a></td></tr
><tr id="gr_svn102_32"

><td id="32"><a href="#32">32</a></td></tr
></table></pre>
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
</td>
<td id="lines">
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
<pre class="prettyprint lang-cpp"><table id="src_table_0"><tr
id=sl_svn102_1

><td class="source">//////////////////////////////////////////////////////////////////////<br></td></tr
><tr
id=sl_svn102_2

><td class="source">// OpenTibia - an opensource roleplaying game<br></td></tr
><tr
id=sl_svn102_3

><td class="source">//////////////////////////////////////////////////////////////////////<br></td></tr
><tr
id=sl_svn102_4

><td class="source">// XML implementation of the Map Loader/Saver<br></td></tr
><tr
id=sl_svn102_5

><td class="source">//////////////////////////////////////////////////////////////////////<br></td></tr
><tr
id=sl_svn102_6

><td class="source">// This program is free software; you can redistribute it and/or<br></td></tr
><tr
id=sl_svn102_7

><td class="source">// modify it under the terms of the GNU General Public License<br></td></tr
><tr
id=sl_svn102_8

><td class="source">// as published by the Free Software Foundation; either version 2<br></td></tr
><tr
id=sl_svn102_9

><td class="source">// of the License, or (at your option) any later version.<br></td></tr
><tr
id=sl_svn102_10

><td class="source">// <br></td></tr
><tr
id=sl_svn102_11

><td class="source">// This program is distributed in the hope that it will be useful,<br></td></tr
><tr
id=sl_svn102_12

><td class="source">// but WITHOUT ANY WARRANTY; without even the implied warranty of<br></td></tr
><tr
id=sl_svn102_13

><td class="source">// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the<br></td></tr
><tr
id=sl_svn102_14

><td class="source">// GNU General Public License for more details.<br></td></tr
><tr
id=sl_svn102_15

><td class="source">//<br></td></tr
><tr
id=sl_svn102_16

><td class="source">// You should have received a copy of the GNU General Public License<br></td></tr
><tr
id=sl_svn102_17

><td class="source">// along with this program; if not, write to the Free Software Foundation,<br></td></tr
><tr
id=sl_svn102_18

><td class="source">// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.<br></td></tr
><tr
id=sl_svn102_19

><td class="source">//////////////////////////////////////////////////////////////////////<br></td></tr
><tr
id=sl_svn102_20

><td class="source">#include &quot;otpch.h&quot;<br></td></tr
><tr
id=sl_svn102_21

><td class="source"><br></td></tr
><tr
id=sl_svn102_22

><td class="source">#include &quot;iomapxml.h&quot;<br></td></tr
><tr
id=sl_svn102_23

><td class="source">#include &quot;iomapserialize.h&quot;<br></td></tr
><tr
id=sl_svn102_24

><td class="source">#include &quot;map.h&quot;<br></td></tr
><tr
id=sl_svn102_25

><td class="source">#include &quot;house.h&quot;<br></td></tr
><tr
id=sl_svn102_26

><td class="source">#include &quot;spawn.h&quot;<br></td></tr
><tr
id=sl_svn102_27

><td class="source"><br></td></tr
><tr
id=sl_svn102_28

><td class="source">bool IOMapXML::loadMap(Map* map, const std::string&amp; identifier)<br></td></tr
><tr
id=sl_svn102_29

><td class="source">{<br></td></tr
><tr
id=sl_svn102_30

><td class="source">	IOMapSerialize xmlMap;<br></td></tr
><tr
id=sl_svn102_31

><td class="source">	return xmlMap.loadMap(map);<br></td></tr
><tr
id=sl_svn102_32

><td class="source">}<br></td></tr
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
 <a href="/p/avesta74/source/detail?spec=svn102&amp;r=91">r91</a>
 by r...@ymail.com
 on Jul 17, 2012
 &nbsp; <a href="/p/avesta74/source/diff?spec=svn102&r=91&amp;format=side&amp;path=/trunk/src/iomapxml.cpp&amp;old_path=/trunk/src/iomapxml.cpp&amp;old=7">Diff</a>
 </div>
 <pre>compilation fix and some minor changes</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/avesta74/source/detail?r=91&spec=svn102';
 var publish_url = '/p/avesta74/source/detail?r=91&spec=svn102#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/trunk/src/account.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/account.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/account.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/account.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/actions.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/actions.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/allocator.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/allocator.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/ban.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/ban.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/ban.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/ban.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/baseevents.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/baseevents.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/beds.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/beds.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/chat.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/chat.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/combat.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/combat.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/commands.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/commands.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/condition.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/condition.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/configmanager.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/configmanager.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/configmanager.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/configmanager.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/connection.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/connection.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/container.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/container.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/creature.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/creature.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/creatureevent.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/creatureevent.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/database.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/database.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/databasemysql.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/databasemysql.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/databasesqlite.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/databasesqlite.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/enums.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/enums.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/exception.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/exception.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/exception.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/exception.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/fileloader.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/fileloader.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/game.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/game.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/game.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/game.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/globalevent.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/globalevent.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/house.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/house.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/housetile.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/housetile.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/ioaccount.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/ioaccount.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/ioaccount.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/ioaccount.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/iomap.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/iomap.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/iomapserialize.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/iomapserialize.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/iomapserialize.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/iomapserialize.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/iomapxml.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/iomapxml.cpp?r\x3d91\x26spec\x3dsvn102');
 
 var selected_path = '/trunk/src/iomapxml.cpp';
 
 
 changed_paths.push('/trunk/src/iomapxml.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/iomapxml.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/ioplayer.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/ioplayer.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/ioplayer.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/ioplayer.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/item.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/item.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/item.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/item.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/itemloader.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/itemloader.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/items.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/items.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/luascript.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/luascript.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/mailbox.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/mailbox.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/map.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/map.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/map.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/map.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/md5.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/md5.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/monster.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/monster.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/monsters.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/monsters.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/movement.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/movement.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/movement.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/movement.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/networkmessage.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/networkmessage.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/npc.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/npc.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/npc.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/npc.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/otserv.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/otserv.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/otsystem.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/otsystem.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/outfit.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/outfit.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/outfit.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/outfit.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/outputmessage.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/outputmessage.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/player.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/player.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/player.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/player.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/position.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/position.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocol.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocol.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocol.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocol.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocolgame.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocolgame.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocolgame.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocolgame.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/protocollogin.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/protocollogin.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/raids.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/raids.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/rsa.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/rsa.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/scheduler.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/scheduler.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/spawn.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/spawn.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/spells.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/spells.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/spells.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/spells.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/status.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/status.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/talkaction.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/talkaction.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/tasks.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/tasks.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/teleport.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/teleport.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/templates.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/templates.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/thing.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/thing.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/tile.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/tile.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/tile.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/tile.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/tools.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/tools.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/tools.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/tools.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/town.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/town.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/trashholder.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/trashholder.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/vocation.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/vocation.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/vocation.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/vocation.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/waitlist.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/waitlist.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/waypoints.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/waypoints.h?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/weapons.cpp');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/weapons.cpp?r\x3d91\x26spec\x3dsvn102');
 
 
 changed_paths.push('/trunk/src/weapons.h');
 changed_urls.push('/p/avesta74/source/browse/trunk/src/weapons.h?r\x3d91\x26spec\x3dsvn102');
 
 
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
 
 <option value="/p/avesta74/source/browse/trunk/src/account.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/account.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/account.h?r=91&amp;spec=svn102"
 
 >/trunk/src/account.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/actions.h?r=91&amp;spec=svn102"
 
 >/trunk/src/actions.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/allocator.h?r=91&amp;spec=svn102"
 
 >/trunk/src/allocator.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/ban.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/ban.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/ban.h?r=91&amp;spec=svn102"
 
 >/trunk/src/ban.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/baseevents.h?r=91&amp;spec=svn102"
 
 >/trunk/src/baseevents.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/beds.h?r=91&amp;spec=svn102"
 
 >/trunk/src/beds.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/chat.h?r=91&amp;spec=svn102"
 
 >/trunk/src/chat.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/combat.h?r=91&amp;spec=svn102"
 
 >/trunk/src/combat.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/commands.h?r=91&amp;spec=svn102"
 
 >/trunk/src/commands.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/condition.h?r=91&amp;spec=svn102"
 
 >/trunk/src/condition.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/configmanager.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/configmanager.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/configmanager.h?r=91&amp;spec=svn102"
 
 >/trunk/src/configmanager.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/connection.h?r=91&amp;spec=svn102"
 
 >/trunk/src/connection.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/container.h?r=91&amp;spec=svn102"
 
 >/trunk/src/container.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/creature.h?r=91&amp;spec=svn102"
 
 >/trunk/src/creature.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/creatureevent.h?r=91&amp;spec=svn102"
 
 >/trunk/src/creatureevent.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/database.h?r=91&amp;spec=svn102"
 
 >/trunk/src/database.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/databasemysql.h?r=91&amp;spec=svn102"
 
 >/trunk/src/databasemysql.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/databasesqlite.h?r=91&amp;spec=svn102"
 
 >/trunk/src/databasesqlite.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/enums.h?r=91&amp;spec=svn102"
 
 >/trunk/src/enums.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/exception.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/exception.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/exception.h?r=91&amp;spec=svn102"
 
 >/trunk/src/exception.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/fileloader.h?r=91&amp;spec=svn102"
 
 >/trunk/src/fileloader.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/game.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/game.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/game.h?r=91&amp;spec=svn102"
 
 >/trunk/src/game.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/globalevent.h?r=91&amp;spec=svn102"
 
 >/trunk/src/globalevent.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/house.h?r=91&amp;spec=svn102"
 
 >/trunk/src/house.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/housetile.h?r=91&amp;spec=svn102"
 
 >/trunk/src/housetile.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/ioaccount.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/ioaccount.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/ioaccount.h?r=91&amp;spec=svn102"
 
 >/trunk/src/ioaccount.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/iomap.h?r=91&amp;spec=svn102"
 
 >/trunk/src/iomap.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/iomapserialize.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/iomapserialize.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/iomapserialize.h?r=91&amp;spec=svn102"
 
 >/trunk/src/iomapserialize.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/iomapxml.cpp?r=91&amp;spec=svn102"
 selected="selected"
 >/trunk/src/iomapxml.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/iomapxml.h?r=91&amp;spec=svn102"
 
 >/trunk/src/iomapxml.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/ioplayer.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/ioplayer.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/ioplayer.h?r=91&amp;spec=svn102"
 
 >/trunk/src/ioplayer.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/item.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/item.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/item.h?r=91&amp;spec=svn102"
 
 >/trunk/src/item.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/itemloader.h?r=91&amp;spec=svn102"
 
 >/trunk/src/itemloader.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/items.h?r=91&amp;spec=svn102"
 
 >/trunk/src/items.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/luascript.h?r=91&amp;spec=svn102"
 
 >/trunk/src/luascript.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/mailbox.h?r=91&amp;spec=svn102"
 
 >/trunk/src/mailbox.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/map.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/map.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/map.h?r=91&amp;spec=svn102"
 
 >/trunk/src/map.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/md5.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/md5.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/monster.h?r=91&amp;spec=svn102"
 
 >/trunk/src/monster.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/monsters.h?r=91&amp;spec=svn102"
 
 >/trunk/src/monsters.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/movement.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/movement.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/movement.h?r=91&amp;spec=svn102"
 
 >/trunk/src/movement.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/networkmessage.h?r=91&amp;spec=svn102"
 
 >/trunk/src/networkmessage.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/npc.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/npc.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/npc.h?r=91&amp;spec=svn102"
 
 >/trunk/src/npc.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/otserv.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/otserv.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/otsystem.h?r=91&amp;spec=svn102"
 
 >/trunk/src/otsystem.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/outfit.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/outfit.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/outfit.h?r=91&amp;spec=svn102"
 
 >/trunk/src/outfit.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/outputmessage.h?r=91&amp;spec=svn102"
 
 >/trunk/src/outputmessage.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/player.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/player.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/player.h?r=91&amp;spec=svn102"
 
 >/trunk/src/player.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/position.h?r=91&amp;spec=svn102"
 
 >/trunk/src/position.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocol.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/protocol.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocol.h?r=91&amp;spec=svn102"
 
 >/trunk/src/protocol.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocolgame.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/protocolgame.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocolgame.h?r=91&amp;spec=svn102"
 
 >/trunk/src/protocolgame.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/protocollogin.h?r=91&amp;spec=svn102"
 
 >/trunk/src/protocollogin.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/raids.h?r=91&amp;spec=svn102"
 
 >/trunk/src/raids.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/rsa.h?r=91&amp;spec=svn102"
 
 >/trunk/src/rsa.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/scheduler.h?r=91&amp;spec=svn102"
 
 >/trunk/src/scheduler.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/spawn.h?r=91&amp;spec=svn102"
 
 >/trunk/src/spawn.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/spells.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/spells.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/spells.h?r=91&amp;spec=svn102"
 
 >/trunk/src/spells.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/status.h?r=91&amp;spec=svn102"
 
 >/trunk/src/status.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/talkaction.h?r=91&amp;spec=svn102"
 
 >/trunk/src/talkaction.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/tasks.h?r=91&amp;spec=svn102"
 
 >/trunk/src/tasks.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/teleport.h?r=91&amp;spec=svn102"
 
 >/trunk/src/teleport.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/templates.h?r=91&amp;spec=svn102"
 
 >/trunk/src/templates.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/thing.h?r=91&amp;spec=svn102"
 
 >/trunk/src/thing.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/tile.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/tile.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/tile.h?r=91&amp;spec=svn102"
 
 >/trunk/src/tile.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/tools.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/tools.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/tools.h?r=91&amp;spec=svn102"
 
 >/trunk/src/tools.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/town.h?r=91&amp;spec=svn102"
 
 >/trunk/src/town.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/trashholder.h?r=91&amp;spec=svn102"
 
 >/trunk/src/trashholder.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/vocation.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/vocation.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/vocation.h?r=91&amp;spec=svn102"
 
 >/trunk/src/vocation.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/waitlist.h?r=91&amp;spec=svn102"
 
 >/trunk/src/waitlist.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/waypoints.h?r=91&amp;spec=svn102"
 
 >/trunk/src/waypoints.h</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/weapons.cpp?r=91&amp;spec=svn102"
 
 >/trunk/src/weapons.cpp</option>
 
 <option value="/p/avesta74/source/browse/trunk/src/weapons.h?r=91&amp;spec=svn102"
 
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
 &nbsp; <a href="/p/avesta74/source/diff?spec=svn102&r=7&amp;format=side&amp;path=/trunk/src/iomapxml.cpp&amp;old_path=/trunk/src/iomapxml.cpp&amp;old=">Diff</a>
 <br>
 <pre class="ifOpened">[No log message]</pre>
 </div>
 
 
 <a href="/p/avesta74/source/list?path=/trunk/src/iomapxml.cpp&start=91">All revisions of this file</a>
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
 
 <div>Size: 1371 bytes,
 32 lines</div>
 
 <div><a href="//avesta74.googlecode.com/svn/trunk/src/iomapxml.cpp">View raw file</a></div>
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
 var paths = {'svn102': '/trunk/src/iomapxml.cpp'}
 codereviews = CR_controller.setup(
 {"assetVersionPath": "https://ssl.gstatic.com/codesite/ph/13997016681179179006", "projectName": "avesta74", "projectHomeUrl": "/p/avesta74", "relativeBaseUrl": "", "loggedInUserEmail": "jose.guitian@coremain.com", "profileUrl": "/u/108692122734644646415/", "token": "ABZ6GAcSi0iA6SDok5j5EkF6eJ_hIrM9FQ:1406096534816", "domainName": null, "assetHostPath": "https://ssl.gstatic.com/codesite/ph"}, '', 'svn102', paths,
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

