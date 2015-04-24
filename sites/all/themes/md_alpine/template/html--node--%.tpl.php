<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"
    <?php print $rdf_namespaces; ?>>

<head profile="<?php print $grddl_profile;?>">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <?php
        print $styles;
        print $scripts;
        global $base_url;
    ?>

    <!-- Start Demandbase / Google Analytics Integration -->
    <!-- This script works along side your current GA integration.
         Place this script after the standard GA tracking code -->
    <script>
        'use strict'; var Demandbase = window.Demandbase || {}; Demandbase.Connectors = window.Demandbase.Connectors || {};
        Demandbase.Connectors.Google_UniversalAnalytics = {
            name: 'Demandbase Universal Analytics Connector', version: '6.1',
            key: 'fcb50e62a47389faff677976f38c6ad40ad713ae',
            fields: {1 : 'industry', 2 : 'revenue_range', 3 : 'isp', 4 : 'company_name', 5 : 'ip', 6 : 'web_site', 7 : 'sub_industry', 8 : 'fortune_1000', 9 : 'forbes_2000', 10 : 'audience', 11:'watch_list_active_cta'},
            pixels: {ad:'1395099048',rt:'1395099101',cn:''},
            CompanyProfile: null, gType: null, logging: true,
            track:function(data) { try { var self = Demandbase.Connectors.Google_UniversalAnalytics, dflt = '(Non-Company Visitor)', awDflt = '(Non-AccountWatch Visitor)'; data = self._flatA(data); self._toGtmDl(data); self.CompanyProfile = data; self._detectG(); for (var field in self.fields) { if (self.fields.hasOwnProperty(field)) { var num = field, lbl = self.fields[field], val = data[self.fields[field]] || dflt, isCompany = (data['company_name'] || dflt) !== dflt; if(data[self.fields[field]] === false) { val = 'false'; } if (lbl.indexOf('watch_list_') !== -1 && isCompany) { val = data[self.fields[field]] || awDflt; } self._var(num, lbl, val.toString()); } } self._event(); } catch (e) { this._logE('Integration Error: ' + e) }; },
            trackConversion:function() { var id = this.pixels['cn']; if (id) { var img = document.createElement('img'), s = document.getElementsByTagName('body')[0]; img.setAttribute('style', 'display:none'); img.setAttribute('alt', 'conversion pixel'); img.id = 'db_cn_pixel'; img.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + "a.company-target.com/pixel?type=js&id=" + id; if('undefined' === typeof s || !s) { s = document.getElementsByTagName('head')[0]; } s.appendChild(img); this._logE('Loaded Script ' + img.src); } },
            load:function(){ try { var pg,db=document.createElement('script'); this.loadPixels(); db.type='text/javascript'; db.async=true; db.id='db_ip_api_ua'; pg=encodeURIComponent(document.URL); if(top !== self) { pg=document.referrer; } db.src=('https:'==document.location.protocol?'https://':'http://')+'api.demandbase.com/api/v2/ip.json?key='+this.key+'&callback=Demandbase.Connectors.Google_UniversalAnalytics.track&page='+pg+'&referrer='+document.referrer; var s=document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(db,s); this._logE('Loaded Script ' + db.src); } catch(e){ this._logE('Script Error: '+e)}; },
            loadPixels: function() { for (var pixel in this.pixels) { if (this.pixels.hasOwnProperty(pixel)) { var id = this.pixels[pixel]; if (id && pixel !== 'cn') { var img = document.createElement('img'), s = document.getElementsByTagName('body')[0]; img.setAttribute('style', 'display:none'); img.setAttribute('alt', 'pixel'); img.id = 'db_' + pixel; img.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + "a.company-target.com/pixel?type=js&id=" + id; if('undefined' === typeof s || !s) { s = document.getElementsByTagName('head')[0]; } s.appendChild(img); this._logE('Loaded Script ' + img.src); } } } },
            _flatA:function(a){ for(var d in a){ if(typeof a[d]=='object'&&a[d]!==null){ for(var cd in a[d]){a[d+'_'+cd]=a[d][cd]}; delete a[d]; } }; return a; },
            _logE:function(m){ if(this.logging && typeof(console) !== 'undefined' && window['console'] !== 'undefined') { console.log('DB UA: ' + m); } },
            _var:function(i,k,v){ if(this.gType === 'ga') { this._p('_setCustomVar', i >> 0, k, v, 1); } else { ga('set','dimension'+i,v); } this._logE(i + ' ' + k +' : ' + v); },
            _event:function(){ if(this.gType === 'ga') { this._p('_trackEvent', 'Demandbase', 'API Resolution', 'IP API', 0, 1); } else { ga("send", "event", { eventCategory: "Demandbase", eventAction: "API Resolution", eventLabel: "IP Address API", nonInteraction: true }); } this._logE('Sent Custom Event: Demandbase/API Resolution/IP Address API'); },
            _cEvent:function(c,a,l){ if(this.gType === 'ga') { this._p('_trackEvent', c, a, l, 0, 1); } else { ga("send", "event", { eventCategory: c, eventAction: a, eventLabel: l, nonInteraction: true }); } this._logE('Sent Custom Event:'+c+'/'+a+'/'+l); },
            _p: function(t, v1, v2, v3, v4, v5) { window._gaq.push([t, v1, v2, v3, v4, v5]); },
            _toGtmDl: function(data) { if (window.google_tag_manager && window.dataLayer) { dataLayer.push(data); dataLayer.push({ event:"Demandbase_Loaded" }); this._logE('Pushed to GTM dataLayer'); } },
            _detectG: function() { if(typeof window.ga === 'function') { this.gType = 'ua'; } else if(window._gaq) { this.gType = 'ga'; _gaq.push(['_addDevId', 'NE7T9']); } else { if(!window.ga) window.ga = function(){(ga.q=ga.q||[]).push(arguments)}; this.gType = 'ua'; } this._logE('Detected Google version: ' + this.gType); }
        };
        Demandbase.Connectors.Google_UniversalAnalytics.load();
    /* End Demandbase integration */
    </script>
    <!-- End Demandbase / Google Analytics -->

    <link href='http://fonts.googleapis.com/css?family=PT+Sans+Narrow:400,700' rel='stylesheet' type='text/css'>
    <style type="text/css">
        <?php if (isset($googlewebfonts)): print $googlewebfonts; endif; ?>
        <?php if (isset($theme_setting_css)): print $theme_setting_css; endif; ?>
        <?php
        // custom typography
        if (isset($typography)): print $typography; endif;
        ?>
        <?php if (isset($custom_css)): print $custom_css; endif; ?>
    </style>
    <?php if (isset($header_code)): print $header_code; endif;?>
</head>
<body data-spy="scroll" data-target=".navbar" data-offset="75" class="blog-page <?php print $classes; ?>" <?php print $attributes;?> >
<?php print $page_top; ?>
<?php print $page; ?>
<?php
print $page_bottom;
if (isset($footer_code)): print $footer_code; endif;
?>
</body>

</html>
