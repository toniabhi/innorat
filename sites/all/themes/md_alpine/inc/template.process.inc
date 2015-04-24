<?php
/**
 * Add body classes if certain regions have content.
 */
function md_alpine_preprocess_html(&$vars) {
    global $base_url;
    $css = "";
    $themepath = drupal_get_path('theme', 'md_alpine');
    drupal_add_js(array('themePath' => $themepath),'setting');
    if(module_exists('icon') && module_exists('fontello')) {
        $icon_bundles = icon_bundles();
        foreach($icon_bundles as $key => $value) {
            if($value['status'] == 1) {
                fontello_process_attached($key);
            }
        }
    }
    drupal_add_css($themepath . '/css/loader.css');
    drupal_add_css($themepath . '/css/normalize.css');
    drupal_add_css($themepath . '/css/bootstrap.min.css');
    drupal_add_css($themepath . '/css/font-awesome.min.css');
    drupal_add_css($themepath . '/css/flexslider.css');
    drupal_add_css($themepath . '/css/owl.carousel.css');
    drupal_add_css($themepath . '/css/own.theme.css');
    drupal_add_css($themepath . '/css/style.css');
    drupal_add_css($themepath . '/css/style-responsive.css');
    drupal_add_css($themepath . '/css/isotope.css');

    $skin = theme_get_setting('skins');
    if($skin != null) {
        drupal_add_css($themepath . '/css/colors/'.$skin.'.css');
    } else {
        drupal_add_css($themepath . '/css/colors/blu.css');
    }
    drupal_add_js($themepath . '/js/lib/jquery.browser.js');
    drupal_add_js($themepath . '/js/lib/modernizr.js');
    drupal_add_js($themepath . '/js/lib/jquery.mb.YTPlayer.js');
    drupal_add_js($themepath . '/js/lib/jquery.sticky.js');
    // drupal_add_js($themepath . '/js/lib/jquery.fitvids.js');
    drupal_add_js($themepath . '/js/lib/jquery.easing-1.3.pack.js');
    drupal_add_js($themepath . '/js/lib/bootstrap.min.js');
    drupal_add_js($themepath . '/js/lib/bootstrap-modal.js');
    drupal_add_js($themepath . '/js/lib/jquery.parallax-1.1.3.js');
    drupal_add_js($themepath . '/js/lib/jquery-countTo.js');
    drupal_add_js($themepath . '/js/lib/jquery.appear.js');
    drupal_add_js($themepath . '/js/lib/jquery.easy-pie-chart.js');
    drupal_add_js($themepath . '/js/lib/jquery.cycle.all.js');
    drupal_add_js($themepath . '/js/lib/jquery.maximage.js');
    drupal_add_js($themepath . '/js/lib/jquery.isotope.min.js');
    drupal_add_js($themepath . '/js/lib/skrollr.js');
    drupal_add_js($themepath . '/js/lib/jquery.flexslider-min.js');
    drupal_add_js($themepath . '/js/lib/jquery.hoverdir.js');
    drupal_add_js($themepath . '/js/lib/owl.carousel.min.js');
    drupal_add_js($themepath . '/js/lib/jquery.validate.min.js');
    drupal_add_js($themepath . '/js/lib/portfolio_custom.js');
    drupal_add_js($themepath . '/js/script.js');
    drupal_add_js($themepath . '/js/lib/retina-1.1.0.min.js');
    // drupal_add_js($themepath . '/js/jquery.fitvids.js');
    //drupal_add_js('http://maps.google.com/maps/api/js?sensor=false');

    /* ------------------------- Add favicon Page ------------------------*/
    if (theme_get_setting('toggle_favicon') == 1) {
        $favicon_path = '';
        if(theme_get_setting('default_favicon') == 1) {
            $favicon = theme_get_setting('fvicon_path');
            $favicon_path = md_alpine_theme_setting_check_path($favicon);
        }
    } else {
        $favicon_path = base_url().'/'.$themepath.'/favicon.ico';
    }
    $type = theme_get_setting('favicon_mimetype');
    drupal_add_html_head_link(array('rel' => 'shortcut icon', 'href' => drupal_strip_dangerous_protocols($favicon_path), 'type' => $type));

    /* ------------------------- Blog Page ------------------------*/

    if(in_array('node-type-blog',$vars['classes_array'])) {
        $vars['classes_array'][] = 'blog-page';
    }

    /* ----------------------------------------------- Menu ---------------------------------------------------------*/
    if(theme_get_setting('menu_sticky')) {
        drupal_add_js(array('menuStickyEnable' => theme_get_setting('menu_sticky')),'setting');
    }
    if(theme_get_setting('menu_custom_enable') == 1) {
        if(theme_get_setting('menu_bg_color')) {
            $css .= '#navigation .navbar-inner {background-color: #'.theme_get_setting('menu_bg_color').'}'."\n";
        }
        if(theme_get_setting('menu_link_color')) {
            $css .= '#navigation .navbar-inner li a {color: #'.theme_get_setting('menu_link_color').'}'."\n";
        }
        if(theme_get_setting('menu_link_hover_color')) {
            $css .= '#navigation .navbar-inner li a:hover {color: #'.theme_get_setting('menu_link_hover_color').'}'."\n";
        }
    }

    /* ---------------------------------------------- Header -----------------------------------------------------*/
    $header_bg_type = theme_get_setting('header_background_type');
    drupal_add_js(array('hdBgType' => $header_bg_type),'setting');
    if($header_bg_type == 'custom') {
        if(theme_get_setting('header_slide_effect')) {
            drupal_add_js(array('hdSlideEffect' => theme_get_setting('header_slide_effect')),'setting');
        }
    }
    if($header_bg_type == 'video') {
        if(theme_get_setting('header_video_play') == 1) {
            drupal_add_js(array('headerVideoAutoPlay' => true),'setting');
        } else {
            drupal_add_js(array('headerVideoAutoPlay' => false),'setting');
        }
        if(theme_get_setting('header_video_resolution')){
            $hd_video_res = theme_get_setting('header_video_resolution');
            drupal_add_js(array('headerVideoRes' => $hd_video_res),'setting');
        }
    }
    if(theme_get_setting('header_video_image_fallback')) {
            $css .= '.video-section { background-image: url("'.md_alpine_theme_setting_check_path(theme_get_setting('header_video_image_fallback')).'");}'."\n";
    }
    if($header_bg_type == 'pattern') {
        if(theme_get_setting('header_pt_slide_auto')) {
            drupal_add_js(array('hdPtAutoPlay' => true),'setting');
        } else {
            drupal_add_js(array('hdPtAutoPlay' => false),'setting');
        }
        $css .= ".intro-pattern { background: #000000 url(" . $base_url .'/'. $themepath ."/images/background/patterns/". theme_get_setting('choose_header_pt_pattern') . ".png) repeat scroll center center;}\n";
    }

    /* ----------------------- Parallax  --------------------------*/
    for($i=1;$i<=7;$i++){
        switch($i){
            case 1:
                $id = 'one-parallax';
                break;
            case 2:
                $id = 'two-parallax';
                break;
            case 3:
                $id = 'three-parallax';
                break;
            case 4:
                $id = 'four-parallax';
                break;
            case 5:
                $id = 'five-parallax';
                break;
            case 6:
                $id = 'six-parallax';
                break;
            case 7:
                $id = 'seven-parallax';
                break;
        }
        if(theme_get_setting('pr_'.$i.'_overlay_enable') == TRUE){
            if(theme_get_setting('pr_'.$i.'_overlay_color')) {
                $css .= '#'.$id.' .parallax-background-color { background-color: #'.theme_get_setting(theme_get_setting('pr_'.$i.'_overlay_color')).'; }';
            }
            if(theme_get_setting('pr_'.$i.'_overlay_opacity')) {
                $css .= '#'.$id.' .parallax-background-color { opacity: '.(theme_get_setting('pr_'.$i.'_overlay_opacity')/100).'; }';
            }
        }
        if(theme_get_setting('pr_'.$i.'_bg_image_path')) {
            $css .= '#'.$id.' {background-image : url("'.md_alpine_theme_setting_check_path(theme_get_setting('pr_'.$i.'_bg_image_path')).'");}';
        }
    }

    /* ---------------------------------------------- 404 Page -----------------------------------------------------*/
    if(theme_get_setting('choose_nf_pattern')) {
        $css .= ".nf-pattern { background: #000000 url(" . $base_url .'/'. $themepath ."/images/background/patterns/". theme_get_setting('choose_nf_pattern') . ".png) repeat scroll center center;}\n";
    }
    /* ---------------------------------------------- Google Map -----------------------------------------------------*/
    /*if(theme_get_setting('map_marker_title') != null){
        drupal_add_js(array('mapMarkerTitle' => theme_get_setting('map_marker_title')),'setting');
    } else {
        drupal_add_js(array('mapMarkerTitle' => 'Megadrupal'),'setting');
    }
    if(theme_get_setting('map_marker_description')!= null){
        drupal_add_js(array('mapMarkerDes' => theme_get_setting('map_marker_description')),'setting');
    } else {
        drupal_add_js(array('mapMarkerDes' => 'Ha Noi , Viet Nam'),'setting');
    }
    if(theme_get_setting('map_latlng')!= null){
        drupal_add_js(array('mapLatlng' => theme_get_setting('map_latlng')),'setting');
    } else {
        drupal_add_js(array('mapLatlng' => '40.748395,-73.985542'),'setting');
    }
    if(theme_get_setting('map_types')!= null){
        drupal_add_js(array('mapTypes' => theme_get_setting('map_types')),'setting');
    } else {
        drupal_add_js(array('mapTypes' => 'ROADMAP'),'setting');
    }
    if(theme_get_setting('map_zoom_level')!= null){
        drupal_add_js(array('mapZoom' => theme_get_setting('map_zoom_level')),'setting');
    } else {
        drupal_add_js(array('mapZoom' => 16),'setting');
    }
    if(theme_get_setting('map_latlng')){
            $map_title = theme_get_setting('map_marker_title');
            $map_des = theme_get_setting('map_marker_description');
            $map_latlng = theme_get_setting('map_latlng');
            $map_types = theme_get_setting('map_types');
            $map_zoom_level = theme_get_setting('map_zoom_level');
            $map_js = ' jQuery(document).ready(function() {
        if(jQuery("#map_canvas").size() > 0) {
            jQuery(window).load(function(){
                //Google Map
                var settings = {
                        zoom: '.$map_zoom_level.',
                        center: new google.maps.LatLng('.$map_latlng.'),
                        mapTypeId: google.maps.MapTypeId.'.$map_types.',
                        mapTypeControl: false,
                        scrollwheel: false,
                        draggable: true,
                        mapTypeControlOptions: {style: google.maps.MapTypeControlStyle.DROPDOWN_MENU},
                        navigationControl: false,
                        navigationControlOptions: {style: google.maps.NavigationControlStyle.SMALL}
                    };
                var map = new google.maps.Map(document.getElementById("map_canvas"), settings);
                google.maps.event.addDomListener(window, "resize", function() {
                    var center = map.getCenter();
                    google.maps.event.trigger(map, "resize");
                    map.setCenter(center);
                });
                var contentString =
                    \'<div id="content"><h3>'.$map_title.'</h3><div id="bodyContent"><p>'.$map_des.'</p></div></div>\';
                var infowindow = new google.maps.InfoWindow({
                    content: contentString
                });
                var companyImage = new google.maps.MarkerImage("'.$base_url.'/'.$themepath.'/img/marker.png",
                    new google.maps.Size(120,80), //Width and height of the marker
                    new google.maps.Point(0,0),
                    new google.maps.Point(35,20) //Position of the marker
                );
                var companyPos = new google.maps.LatLng('.$map_latlng.');
                var companyMarker = new google.maps.Marker({
                    position: companyPos,
                    map: map,
                    icon: companyImage,
                    title:"Creative News",
                    zIndex: 3});
                google.maps.event.addListener(companyMarker, "click", function() {
                    infowindow.open(map,companyMarker);
                });
            });
        }
    });';
            drupal_add_js($map_js,array('type' => 'inline','scope' => 'footer'));
    } */

    $vars['theme_setting_css'] = $css;
	// Custom Web clip
	$webclip_path = theme_get_setting('webclip_path');
	if ($webclip_path) {
    $wc_href = "";
		if (file_uri_scheme($webclip_path) == 'public') {
			$wc_href = file_create_url($webclip_path);
		} else {
			$wc_href = file_create_url(file_build_uri($webclip_path));
		}

		$wc_rel = "apple-touch-icon";
	  if (theme_get_setting('webclip_precomp')) { // no output if $url_precomp = ''
	    $wc_rel = "apple-touch-icon-precomposed";
	  }
		$wc = array(
			'#tag' => 'link',
			'#attributes' => array(
				'href' => $wc_href,
				'rel' => $wc_rel,
				'type' => file_get_mimetype($wc_href),
			),
		);
		drupal_add_html_head($wc, 'webclip');
	}

	// Enable Responsive
	if (theme_get_setting('responsive')) {
		$menuid = 'main-menu';
		if (!empty($vars['page']['superfish'])) {
			$tmp_array_keys = array_keys($vars['page']['superfish']);
			$menuid = str_replace("_","-",$tmp_array_keys[0]);
		}
		$selecnav = '(function ($) {
			$(function(){
				selectnav(\''.$menuid.'\', {
					label: \''.t('--- Table of content ---').'\',//first select field
					nested: true,
					indent: \'-\'
			 });
		});
		})(jQuery);';
		drupal_add_js($selecnav, 'inline');
		$vp = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',
          '#attributes' => array(
            'name' =>  'viewport',
            'content' =>  'width=100%, initial-scale=1, maximum-scale=1, minimum-scale=1, user-scalable=no'
          )
        );
        drupal_add_html_head($vp, 'viewport');
	}

    $vars['theme_setting_css'] = $css;
    //Google Fonts
    if(theme_get_setting('googlewebfonts')) {
        drupal_add_css(theme_get_setting('googlewebfonts'),'external');
    }
	// Typekit
	if (theme_get_setting('typekit_id')) {
		drupal_add_js('http://use.typekit.net/'.theme_get_setting('typekit_id').'.js', 'external');
		drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
	}

	/* Text/typography
	---------------------------------------------------------------------------------------- */
	$typography = '';
	// common text
	if (theme_get_setting('text_font') || theme_get_setting('ts_font_color')) {
    $typography = "body {";
    $typography .= md_alpine_font_to_css(theme_get_setting('text_font'));
		if (theme_get_setting('ts_font_color')) {
      $typography .= 'color: #' . theme_get_setting('ts_font_color') . ';';
		}
    $typography   .= "}\n";
	}
    /////
  $text_font_arr = explode("|", theme_get_setting('text_font'));
  if (count($text_font_arr) == 5 && $text_font_arr[0] != '0') {
    $typography   .= '#forum, ul.quicktabs-tabs, #nav ul.sf-menu li li,.ui-widget {font-family: '.$text_font_arr[4].';}';
  }
    /////
	// Text selection
	if (theme_get_setting('tss_bgcolor') || theme_get_setting('tss_tcolor')) {
    $tss_bgcolor = '';
    $tss_tcolor = '';
		if (theme_get_setting('tss_bgcolor')) {
		  $tss_bgcolor   = 'background: #'.theme_get_setting('tss_bgcolor').';';
		}
		if (theme_get_setting('tss_tcolor')) {
		  $tss_tcolor   = 'color: #'.theme_get_setting('tss_tcolor').';';
		}
    $typography   .= "::-moz-selection {". $tss_bgcolor . $tss_tcolor . "text-shadow: none;}\n";
    $typography   .= "::selection {" . $tss_bgcolor . $tss_tcolor. "text-shadow: none;}\n";
	}
	// link regular
	if (theme_get_setting('l_regular_color') || theme_get_setting('l_regular_st') || theme_get_setting('l_regular__hl') || theme_get_setting('l_regular_ts')) {
    $typography   .= "a:link, #node-title a {";
		if (theme_get_setting('l_regular_color')) {
      $typography   .= 'color: #'.theme_get_setting('l_regular_color').';';
		}
		if (theme_get_setting('l_regular__hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_regular__hlc').';';
		}
        if(theme_get_setting('l_regular_st') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_regular_ts');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}
	// link rollover
	if (theme_get_setting('l_rollover_color') || theme_get_setting('l_rollover_st') || theme_get_setting('l_rollover__hl') || theme_get_setting('l_rollover_ts')) {
		$typography   .= "a:hover, #node-title a:hover {";
		if (theme_get_setting('l_rollover_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_rollover_color').';';
		}
		if (theme_get_setting('l_rollover__hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_rollover__hlc').';';
		}
        if(theme_get_setting('l_rollover_st') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_rollover_ts');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}

	// link visited
	if (theme_get_setting('l_visited_color') || theme_get_setting('l_visited_st') || theme_get_setting('l_visited__hl') || theme_get_setting('l_visited_ts')) {
		$typography   .= "a:visited, #node-title a:visited {";
		if (theme_get_setting('l_visited_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_visited_color').';';
		}
		if (theme_get_setting('l_visited__hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_visited__hlc').';';
		}
        if(theme_get_setting('l_visited_st') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_visited_ts');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}

	// link on
	if (theme_get_setting('l_on_color') || theme_get_setting('l_on_st') || theme_get_setting('l_on_hl') || theme_get_setting('l_on_ts')) {
		$typography   .= "a:focus, a:active, #node-title a:focus, #node-title a:active {";
		if (theme_get_setting('l_on_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_on_color').';';
		}
		if (theme_get_setting('l_on_hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_on_hlc').';';
		}
        if(theme_get_setting('l_on_st') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_on_ts');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}
	// Main menu
	if (theme_get_setting('typo_menu_style') || theme_get_setting('typo_menu_color')) {
		$typography   .= "#menu li{";
		if (theme_get_setting('text_font')) {
		  $typography   .= md_alpine_font_to_css(theme_get_setting('typo_menu_style'));
		}

		if (theme_get_setting('typo_menu_color')) {
		  $typography   .= 'color: #'.theme_get_setting('typo_menu_color').';';
		}
		$typography   .= "}\n";

		if (theme_get_setting('typo_menu_color')) {
		  $typography   .= '#menu li a, #nav ul.sf-menu li a {color: #'.theme_get_setting('typo_menu_color').';}';
		}
		if (theme_get_setting('typo_menu_hover_color')) {
		  $typography   .= '#menu li > a:hover,#menu li.sfHover > a, #main li:hover a {color: #'.theme_get_setting('typo_menu_hover_color').';}'."\n";
		}
		if (theme_get_setting('typo_menu_active_color')) {
		  $typography   .= '#menu li > a:hover, #menu li.sfHover > a, #menu li a.active, #menu li.active a {color: #'.theme_get_setting('typo_menu_active_color').';}'."\n";
		}
	}
    /*-------------------------------------- Heading --------------------------------*/
    if(theme_get_setting('typo_heading_style_enable') == 1){
        for($i=1;$i<=6;$i++){
            $typography .= 'h'.$i.' {';
            if(theme_get_setting('typo_heading_h'.$i.'_style') || theme_get_setting('typo_heading_h'.$i.'_color')){
                if(theme_get_setting('typo_heading_h'.$i.'_style')){
                    $typography .= md_alpine_font_to_css(theme_get_setting('typo_heading_h'.$i.'_style'));
                }
                if(theme_get_setting('typo_heading_h'.$i.'_color')){
                    $typography .= ' color: #'.theme_get_setting('typo_heading_h'.$i.'_color').';';
                }
            }
            $typography .= "}\n";
        }
    }
	/*------------------------------------ Node title ---------------------------------*/
	if (theme_get_setting('typo_nodetitle_style') || theme_get_setting('nodetitle_color')) {
		$typography   .= "#node-title {";
		if (theme_get_setting('typo_nodetitle_style')) {
		  $typography   .= md_alpine_font_to_css(theme_get_setting('typo_nodetitle_style'));
		}

		if (theme_get_setting('nodetitle_color')) {
		  $typography   .= 'color: #'.theme_get_setting('nodetitle_color').';';
		}
		$typography   .= "}\n";

		if (theme_get_setting('nodetitle_color')) {
		  $typography   .= '#node-title a {color: #'.theme_get_setting('nodetitle_color').';}'."\n";
		}

		if (theme_get_setting('nodetitle_hover_color')) {
		  $typography   .= '#node-title a:hover {color: #'.theme_get_setting('nodetitle_hover_color').';}'."\n";
		}
	}

	if (theme_get_setting('nodetitle_enable') == 1) {
		foreach (node_type_get_types() as $type => $name) {
			if (theme_get_setting('typo_n'.$type.'title_style') || theme_get_setting('n'.$type.'title_color')) {
				$typography   .= "#node-title span.node-$type-title {";
				if (theme_get_setting('typo_n'.$type.'title_style')) {
				  $typography   .= md_alpine_font_to_css(theme_get_setting('typo_n'.$type.'title_style'));
				}

				if (theme_get_setting('n'.$type.'title_color')) {
				  $typography   .= 'color: #'.theme_get_setting('n'.$type.'title_color').';';
				}
				$typography   .= "}\n";

				if (theme_get_setting('n'.$type.'title_color')) {
				  $typography   .= '#node-title span.node-'.$type.'-title a {color: #'.theme_get_setting('n'.$type.'title_color').';}'."\n";
				}

				if (theme_get_setting('n'.$type.'title_hover_color')) {
				  $typography   .= '#node-title span.node-'.$type.'-title a:hover {color: #'.theme_get_setting('n'.$type.'title_hover_color').';}'."\n";
				}
			}
		}
	}

    // View block title
    if (theme_get_setting('typo_view_title_style') || theme_get_setting('typo_view_title_color')) {
        $typography   .= ".flx-intro-2 h2 {";
        if (theme_get_setting('typo_view_title_style')) {
            $typography   .= md_alpine_font_to_css(theme_get_setting('typo_view_title_style'));
        }

        if (theme_get_setting('typo_view_title_color')) {
            $typography   .= 'color: #'.theme_get_setting('typo_view_title_color').' !important;';
        }
        $typography   .= "}\n";

    }

    if (theme_get_setting('typo_view_title_enable') == 1) {
        $views = views_get_all_views($reset = FALSE);
        foreach ($views as $view_name => $view) {
            if(($view->disabled) !== true){
                $view_title = $view->name;

                if (theme_get_setting('typo_view_'.$view_title.'_title_style') || theme_get_setting('typo_view_'.$view_title.'_title_color')) {
                    $typography   .= ".flx-intro-2 h2.view-".$view_title."-title {";
                    if (theme_get_setting('typo_view_'.$view_title.'_title_style')) {
                        $typography   .= md_alpine_font_to_css(theme_get_setting('typo_view_'.$view_title.'_title_style'));
                    }

                    if (theme_get_setting('typo_view_'.$view_title.'_title_color')) {
                        $typography   .= 'color: #'.theme_get_setting('typo_view_'.$view_title.'_title_color').' !important;';
                    }
                    $typography   .= "}\n";
                }
            }

        }
    }
    //View block description
    if (theme_get_setting('typo_view_description_style') || theme_get_setting('typo_view_description_color')) {
        $typography   .= ".flx-intro-2 h5.flx-intro-excerpt {";
        if (theme_get_setting('typo_view_description_style')) {
            $typography   .= md_alpine_font_to_css(theme_get_setting('typo_view_description_style'));
        }

        if (theme_get_setting('typo_view_description_color')) {
            $typography   .= 'color: #'.theme_get_setting('typo_view_description_color').' !important;';
        }
        $typography   .= "}\n";

    }

    if (theme_get_setting('typo_view_description_enable') == 1) {
        $views = views_get_all_views($reset = FALSE);
        foreach ($views as $view_name => $view) {
            if(($view->disabled) !== true){
                $view_title = $view->name;

                if (theme_get_setting('typo_view_'.$view_title.'_description_style') || theme_get_setting('typo_view_'.$view_title.'_description_color')) {
                    $typography   .= ".flx-intro-2 span.view-".$view_title."-description {";
                    if (theme_get_setting('typo_view_'.$view_title.'_description_style')) {
                        $typography   .= md_alpine_font_to_css(theme_get_setting('typo_view_'.$view_title.'_description_style'));
                    }

                    if (theme_get_setting('typo_view_'.$view_title.'_description_color')) {
                        $typography   .= 'color: #'.theme_get_setting('typo_view_'.$view_title.'_description_color').' !important;';
                    }
                    $typography   .= "}\n";
                }
            }

        }
    }
    if (theme_get_setting('typo_webformtitle_style') || theme_get_setting('typo_webformtitle_color')) {
        $typography   .= ".flx-map-form span.webform-title{";
        if (theme_get_setting('typo_webformtitle_style')) {
            $typography   .= md_alpine_font_to_css(theme_get_setting('typo_webformtitle_style'));
        }

        if (theme_get_setting('typo_webformtitle_color')) {
            $typography   .= 'color: #'.theme_get_setting('typo_webformtitle_color').' !important;';
        }
        $typography   .= "}\n";

    }
    if (theme_get_setting('typo_webformdescription_style') || theme_get_setting('typo_webformdescription_color')) {
        $typography   .= ".flx-map-form span.webform-description{";
        if (theme_get_setting('typo_webformdescription_style')) {
            $typography   .= md_alpine_font_to_css(theme_get_setting('typo_webformdescription_style'));
        }

        if (theme_get_setting('typo_webformdescription_color')) {
            $typography   .= 'color: #'.theme_get_setting('typo_webformdescription_color').' !important;';
        }
        $typography   .= "}\n";
    }

	$vars['typography'] = $typography;

	/* Get theme settings
	---------------------------------------------------------------------------------------- */
	$vars['footer_text']   = theme_get_setting('footer_text');
	$vars['header_code']   = theme_get_setting('header_code');
	$vars['footer_code']   = theme_get_setting('footer_code');
	if (theme_get_setting('custom_css')) {
		$vars['custom_css']  = theme_get_setting('custom_css');
	}
	drupal_add_css(path_to_theme() . '/css/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
}

function md_alpine_font_to_css($font) {
    $font_arr = explode("|", $font);
    $css = "";
    if(count($font_arr) == 6) {
        if ($font_arr[0] != '0') {
            $css = ''.$font_arr[5].';';
        }
    }
    return $css;
}

function md_alpine_expand_font_weight($fw) {
				switch($fw) {
					case 'n1':
						$fontExpand = "font-style: normal; font-weight: 100;";
				  	break;
					case 'i1':
						$fontExpand = "font-style: italic; font-weight: 100;";
						break;
					case 'n2':
						$fontExpand = "font-style: normal; font-weight: 200;";
				  	break;
					case 'i2':
						$fontExpand = "font-style: italic; font-weight: 200;";
						break;
					case 'n3':
						$fontExpand = "font-style: normal; font-weight: 300;";
				  	break;
					case 'i3':
						$fontExpand = "font-style: italic; font-weight: 300;";
						break;
					case 'n4':
						$fontExpand = "font-style: normal; font-weight: normal;";
				  	break;
					case 'i4':
						$fontExpand = "font-style: italic; font-weight: normal";
						break;
					case 'n5':
						$fontExpand = "font-style: normal; font-weight: 500;";
				  	break;
					case 'i5':
						$fontExpand = "font-style: italic; font-weight: 500;";
						break;
					case 'n6':
						$fontExpand = "font-style: normal; font-weight: 600;";
				  	break;
					case 'i6':
						$fontExpand = "font-style: italic; font-weight: 600;";
						break;
					case 'n7':
						$fontExpand = "font-style: normal; font-weight: bold;";
				  	break;
					case 'i7':
						$fontExpand = "font-style: italic; font-weight: bold;";
						break;
					case 'n8':
						$fontExpand = "font-style: normal; font-weight: 800;";
				  	break;
					case 'i8':
						$fontExpand = "font-style: italic; font-weight: 800;";
						break;
					case 'n9':
						$fontExpand = "font-style: normal; font-weight: 800;";
				  	break;
					case 'i9':
						$fontExpand = "font-style: italic; font-weight: 800;";
						break;
					default:
						$fontExpand = "";
				}

				return $fontExpand;
			}

/**
 * Override or insert vars into the page template for HTML output.
 */
function md_alpine_process_html(&$vars) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($vars);
  }

	$classes = explode(' ', $vars['classes']);
  if ($node = menu_get_object()) {
    $node_type_class = drupal_html_class('node-type-' . $node->type);
    if (in_array($node_type_class, $classes)) {
      theme_get_setting('extra_page_classes') == 0 ? '' : $classes = str_replace($node_type_class, '', $classes);
      $classes = str_replace('node-type-', 'page-type-', $classes);
    }
  }
  $vars['classes'] = trim(implode(' ', $classes));
}



/**
 * Override or insert vars into the page template.
 */
function md_alpine_process_page(&$vars) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($vars);
  }

	$status = drupal_get_http_header("status");
  if($status == "404 Not Found") {
    $vars['theme_hook_suggestions'][] = 'page__404';
  }

	$vars['social_links'] = 0;

  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $vars['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $vars['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($vars['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $vars['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($vars['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $vars['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($vars['title_suffix']['add_or_remove_shortcut']) && $vars['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $vars['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $vars['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $vars['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

}

/**
 * Implements hook_preprocess_page().
 */
function md_alpine_preprocess_page(&$vars, $hook) {
    // Page title in node page
    if(isset($vars['node'])) {
        $node = $vars['node'];
        $vars['page_title'] = $vars['node']->type;
        // Check and create previous and next link of current node
        $nid = $node->nid;
        $node_type = $node->type;
        $query = db_select('node', 'n');
        $query->fields('n', array('nid'))
            ->condition('type', $node_type)
            ->orderBy('nid');
        $result = $query->execute();
        $nids = array();
        while ($record = $result->fetchAssoc()) {
            $nids[] .= $record['nid'];
        }
        $current_node_key =  array_search($nid, $nids);
        if(($current_node_key-1) > 0) {
            $vars['previous_link'] = url('node/'.$nids[$current_node_key-1],array('absolute'=>true));
        }
        if(($current_node_key + 1) != sizeof($nids)) {
            $vars['next_link'] = url('node/'.$nids[$current_node_key+1],array('absolute'=>true));
        }
    }
    if(theme_get_setting('footer_text')){
        $vars['footer_text'] = theme_get_setting('footer_text');
    }

    $themepath = drupal_get_path('theme', 'md_alpine');

  if (drupal_is_front_page()) {
    $description = array(
      '#tag' => 'meta',
      '#attributes' => array(
         'name' => 'description',
         'content' => "Women Lead Australia: An initiative by HCL Tech and Women & Leadership Australia. It is helping connect executive leaders with emerging corporate women leaders.",
      ),
    );
    drupal_add_html_head($description, 'metatag');
    $keywords = array(
      '#tag' => 'meta',
      '#attributes' => array(
         'name' => 'keywords',
         'content' => "women in leadership, leadership courses, women leadership, global leadership program, women as leaders, executive leadership australia",
      ),
    );
    drupal_add_html_head($keywords, 'metatag');
    drupal_set_title('Women Lead Australia: A Leadership Initiative');
  }
}
/**
 * Implements hook_preprocess_maintenance_page().
 */
function md_alpine_preprocess_maintenance_page(&$vars) {
    $theme_path = drupal_get_path('theme','md_alpine');
    if(module_exists('fontello')) {
        drupal_add_css(drupal_get_path('module','fontello').'/css/fontello.fix.css');
        drupal_add_css('public://icon/fontello/fontello/css/fontello.css');
        drupal_add_css('public://icon/fontello/fontello/css/animation.css');
    }

    /********************************** Skin ********************************/
    if (theme_get_setting('skins') != '0') {
        drupal_add_css($theme_path . '/css/colors/'.theme_get_setting('skins').'.css', array('group' => CSS_THEME));
    }
    if (!$vars['db_is_active']) {
        unset($vars['site_name']);
    }
    // Always print the site name and slogan, but if they are toggled off, we'll
    // just hide them visually.
    $vars['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
    $vars['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
    if ($vars['hide_site_name']) {
        // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
        $vars['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
    }
    if ($vars['hide_site_slogan']) {
        // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
        $vars['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
    }
}

function md_alpine_check_und($param) {
	if (isset($param['und'])) {
		return $param['und'][0];
	} else {
		return $param[0];
	}
}
function theme_path() {
    $theme_path = drupal_get_path('theme','md_alpine');

    return $theme_path;
}
function get_skin_color ($skin_name) {
    $color = '';
    switch ($skin_name) {
        case 'default':
            $color = '#bba454';
            break;
        case 'yellow':
            $color = '#e5ae09';
            break;
        case 'green':
            $color = '#9cc045';
            break;
        case 'ruby':
            $color = '#cc144d';
            break;
        case 'teal':
            $color = '#14b4cc';
            break;
        case 'blue':
            $color = '#6ac0d5';
            break;
        case 'orange':
            $color = '#ee5e07';
            break;
        case 'purple':
            $color = '#7e599d';
            break;
    }
    return $color;
}
