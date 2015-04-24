<?php

/**
 * @file
 * Theme settings .
 */

function md_alpine_theme_settings_design(&$form, &$form_state) {
    global $base_url;
    $options = array();
    foreach (icon_bundles() as $bundle_name => $bundle) {
        if (!$bundle['status']) {
            continue;
        }
        foreach ($bundle['icons'] as $icon_key => $icon_value) {
            $icon_name = is_string($icon_key) ? $icon_key : $icon_value;
            if (is_array($icon_value) && isset($icon_value['name'])) {
                $icon_name = $icon_value['name'];
            }
            $icon_title = is_string($icon_value) ? $icon_value : $icon_name;
            if (is_array($icon_value) && isset($icon_value['title'])) {
                $icon_title = $icon_value['title'];
            }
            $options[$bundle['title']][$bundle['name'] . '|' . $icon_name] = $icon_title;
        }
    $icon_default_value = $options;
    }
    $icon_mark_up = '';
    $icon_fake_markup = '<ul class="list-icon">';
    foreach($icon_default_value as $key => $value) {
        $icon_mark_up .= '<option selected="selected" value="">- No Icon -</option><optgroup label="'.$key.'">';
        foreach ($icon_default_value[$key] as $key2 => $value2) {
            $fake_icon_explode = explode("|",$key2);
            $icon_fake_markup .= '<li><a href="javascript:;" class="fake-icon" icon-name="'.$fake_icon_explode[1].'" data-icon="'.$key2.'"><i class="'.$fake_icon_explode[0].' '.$fake_icon_explode[1].'"></i></a></li>';
            $icon_mark_up .= '<option value="'.$key2.'">'.$value2.'</option>';
        }
        $icon_mark_up .= '</optgroup>';
    }
    $icon_fake_markup .= '</ul>';
    drupal_add_js(array('iconMarkUp' => $icon_mark_up),'setting');
    drupal_add_js(array('iconFakeMarkUp' => $icon_fake_markup),'setting');

	$form['md_alpine_settings']['design'] = array(
		'#type' 					=> 'fieldset',
		'#weight' 				=> -4,
		'#prefix'  				=> '<div id="md-design" class="md-tabcontent clearfix">',
		'#suffix'        => '</div><!-- / #md-design -->',
	);
	
	$form['md_alpine_settings']['design']['design_htmllist'] = array(
		'#markup' 				=> '<div class="md-listleft">
				<ul>
				    <li><a href="#ds-general">Skins</a></li>
				    <li><a href="#ds-menu">Menu</a></li>
				    <li><a href="#ds-sidebar">Sidebar</a></li>
				    <li><a href="#ds-header">Header</a></li>
					<li><a href="#ds-parallax">Parallax</a></li>
					<li><a href="#ds-footer">Footer</a></li>
					<li><a href="#ds-team">About Us</a></li>
                    <li><a href="#ds-nf">404 Page</a></li>
				</ul>
			</div><div class="md-listcontent">',
		'#weight' 				=> -15,
	);
	$form['md_alpine_settings']['design']['design_htmllistclose'] = array(
		'#markup' 				=> '</div><!-- /.md-listleft -->',
		'#weight' 				=> 15,
	);
    $form['md_alpine_settings']['design']['design_general'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -5,
        '#prefix'  				=> '<div id="ds-general" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    // Site skins
    $form['md_alpine_settings']['design']['design_general']['skins'] = array(
        '#type'          => 'select',
        '#title'         => t('Choose skin'),
        '#default_value' => theme_get_setting('skins'),
        '#options'       => array(
            'blu'   => t('Default (Blue)'),
            'green' 	=> t('Green'),
            'lightviolet' 	    => t('Light Violet'),
            'orange' 	    => t('Orange'),
            'red' 	=> t('Red'),
            'violet' 	=> t('Violet'),
        ),
        '#prefix' => '<div id="design-skins" class="clearfix">',
        '#suffix' => '</div>',
    );
    /* 2.   Menu
    --------------------------------------------------------------------------*/
    $form['md_alpine_settings']['design']['design_menu'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -5,
        '#prefix'  				=> '<div id="ds-menu" class="md-tabcontent clearfix"><h3>Menu Configuration</h3>',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    $form['md_alpine_settings']['design']['design_menu']['menu_sticky'] = array(
        '#type' => 'checkbox',
        '#title'    => 'Enable Menu Sticky',
        '#default_value'    => theme_get_setting('menu_sticky')
    );
    $form['md_alpine_settings']['design']['design_menu']['menu_custom_enable'] = array(
        '#type' => 'checkbox',
        '#title'    => 'Enable Custom Menu',
        '#default_value'    => theme_get_setting('menu_custom_enable') ? theme_get_setting('menu_custom_enable') : 0,
    );
    $form['md_alpine_settings']['design']['design_menu']['menu_custom'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="menu-custom">',
        '#suffix'   => '</div>',
        '#states'   => array(
            'visible'   => array(
                ':input[name="menu_custom_enable"]' => array('checked' => TRUE),
            )
        )
    );
    $form['md_alpine_settings']['design']['design_menu']['menu_custom']['menu_bg_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Menu Background Color'),
        '#default_value' => theme_get_setting('menu_bg_color') ? theme_get_setting('menu_bg_color') : '',
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_menu']['menu_custom']['menu_link_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Menu Link Color'),
        '#default_value' => theme_get_setting('menu_link_color') ? theme_get_setting('menu_link_color') : '',
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_menu']['menu_custom']['menu_link_hover_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Menu Link Hover Color'),
        '#default_value' => theme_get_setting('menu_link_hover_color') ? theme_get_setting('menu_link_hover_color') : '',
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>'
    );
    /* 3.Sidebar
    --------------------------------------------------------------------------*/
    $form['md_alpine_settings']['design']['design_sidebar'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -5,
        '#prefix'  				=> '<div id="ds-sidebar" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_alpine_settings']['design']['design_sidebar']['sidebar_position'] = array(
        '#type'          => 'select',
        '#title'         => t('Sidebar position'),
        '#default_value' => theme_get_setting('sidebar_position') ? theme_get_setting('sidebar_position') : 'right',
        '#options'       => array(
            'no'        => t('No sidebar'),
            'left'      => t('Left'),
            'right' 	=> t('Right'),
        ),
    );
    /* 4.   Header
    --------------------------------------------------------------------------*/
    $form['md_alpine_settings']['design']['design_header'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -6,
        '#prefix'  				=> '<div id="ds-header" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_alpine_settings']['design']['design_header']['header_background_type'] = array(
        '#type' => 'select',
        '#title'    => 'Choose header background type',
        '#options'  => array(
            'md_fullscreen_slider' => 'MD Fullscreen Slider',
            'custom'    => 'Custom Slide Maximage',
            'video'     => ' Custom Video Background (only support youtube)',
            'pattern'     => 'Custom Pattern Slider',
        ),
        '#default_value'    => theme_get_setting('header_background_type'),
        '#attributes'   => array(
            'class' => array('header-background-type')
        ),
        '#description' => 'To use MD Fullscreen Slider you need remove "Header Block" from header region and replace with your custom slider block '.l('here',''.$base_url.'/admin/structure/block'),
    );
   
    $form['md_alpine_settings']['design']['design_header']['header_video'] = array(
        '#type' => 'fieldset',
        '#title' => 'Custom Video Background',
        '#prefix' => '<div id="header-video-wrapper">',
        '#suffix' => '</div>',
        '#attributes' => array(
            'class' => array('header-video-wrapper'),
        )
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['header_video_play'] =  array(
        '#type' => 'checkbox',
        '#title'    => 'Auto Play Video',
        '#default_value'    => theme_get_setting('header_video_play'),
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['header_video_resolution'] =  array(
        '#type' => 'select',
        '#title'    => 'Choose Video Resolution',
        '#options'  => array(
            'default'   => 'Default',
            'medium'    => 'Medium',
            'small'     => 'Small',
            'large'     => 'Large',
            'hd720'     => 'Hd720',
            'hd1080'     => 'Hd1080',
            'highres'     => 'HighRes',
        ),
        '#default_value'    => theme_get_setting('header_video_resolution'),
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['header_video_link'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Video Link',
        '#attributes' => array(
            'class' => array('header_video_link'),
        ),
        '#default_value'    => theme_get_setting('header_video_link'),
        '#maxlength' => 1000,
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['header_video_image_fallback'] = array(
        '#type' => 'textfield',
        '#title' => '<h3>Video Fallback Image</h3>',
        '#default_value' =>  theme_get_setting('header_video_image_fallback'),
        '#description' => 'This image use for display when video stop, pause or display in mobile device',
        '#maxlength' => 255,
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['header_video_image_fallback_upload'] = array(
        '#type' => 'file',
    );

    /* -------------------------------------------Header Video -------------------------------------------------- */
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd-vd-content-wrapper" class="hd-vd-content-wrapper">',
        '#suffix'   => '</div>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd-vd-slide-wrapper" class="hd-vd-slide-wrapper"><h3>Header Video Slide Content</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('hd_vd_slide_max_num') ? theme_get_setting('hd_vd_slide_max_num') : 1;
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="hd_vd_slide_preview" data-max-num="'.$max_num.'" href="#hd-vd-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd_vd_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('hd_vd_slide_max_num') ? theme_get_setting('hd_vd_slide_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview']["hd_vd_preview_openhtml"] = array(
        '#markup'   => '<ul id="hd_vd_slide_sortable" class="sortable">'
    );
    if(theme_get_setting('hd_vd_slide') && count(theme_get_setting('hd_vd_slide')) > 1) {
        $hd_vd_slide = theme_get_setting('hd_vd_slide');
        foreach($hd_vd_slide as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="hd-vd-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="hd-vd-slide-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview'][$key]['hd_vd_slide_before_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Slide Before Title',
                '#default_value'    => $hd_vd_slide[$key]['before_title'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview'][$key]['hd_vd_slide_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Slide Title',
                '#default_value'    => $hd_vd_slide[$key]['title'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview'][$key]['hd_vd_slide_after_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Slide After Title',
                '#default_value'    => $hd_vd_slide[$key]['after_title'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview'][$key]['hd_vd_slide_des_'.$num] = array(
                '#type' => 'textarea',
                '#title'    => 'Slide Description',
                '#resizable'    => FALSE,
                '#default_value'    => $hd_vd_slide[$key]['des'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview']['hd_vd_slide_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="hd-vd-slide-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="hd-vd-slide-sortable-no1">'
        );
        $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview']['hd_vd_slide_before_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Slide Before Title',
            '#default_value'    => theme_get_setting('hd_vd_slide_before_title_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview']['hd_vd_slide_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Slide Title',
            '#default_value'    => theme_get_setting('hd_vd_slide_title_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview']['hd_vd_slide_after_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Slide After Title',
            '#default_value'    => theme_get_setting('hd_vd_slide_after_title_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview']['hd_vd_slide_des_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Slide Description',
            '#resizable'    => FALSE,
            '#default_value'    => theme_get_setting('hd_vd_slide_des_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview']['hd_vd_slide_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['hd_vd_slide_content_wrapper']['hd_vd_slide_preview']["hd_vd_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['header_vd_button'] = array(
        '#type' => 'fieldset',
        '#prefix'    => '<h3>Header Video Button</h3>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['header_vd_button']['header_vd_ti_button_text'] = array(
        '#type' => 'textfield',
        '#title' => 'Button Text',
        '#default_value'    => theme_get_setting('header_vd_ti_button_text')
    );

    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['header_vd_button']['header_vd_ti_button_text_hover'] = array(
        '#type' => 'textfield',
        '#title' => 'Button Text Hover',
        '#default_value'    => theme_get_setting('header_vd_ti_button_text_hover')
    );
    $form['md_alpine_settings']['design']['design_header']['header_video']['hd_vd_content']['header_vd_button']['header_vd_ti_button_link'] = array(
        '#type' => 'textfield',
        '#title' => 'Button Link',
        '#default_value'    => theme_get_setting('header_vd_ti_button_link')
    );

    $form['md_alpine_settings']['design']['design_header']['header_content'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="header-image-wrapper"><h2>Custom Header Slide</h2>',
        "#suffix"   => '</div>',
    );

    $form['md_alpine_settings']['design']['design_header']['header_content']['header_content_wrapper'] = array(
        '#type' => ' fieldset',
        '#title' => 'Header Content Display',
        '#prefix'   => '<div id="header-content-wrapper">',
        '#suffix'   => '</div>'
    );

    $form['md_alpine_settings']['design']['design_header']['header_content']['header_content_wrapper']['header_slide_effect'] = array(
        '#type' => 'select',
        '#prefix'   => '<div id="header-slide-effect">',
        '#suffix'   =>  '</div>',
        '#title'    => 'Choose Slide Image Effect',
        '#options'  => array(
            'linear' => 'Linear',
            'swing'   => 'Swing',
            'easeInQuad'   => 'easeInQuad',
            'easeOutQuad'  => 'easeOutQuad',
            'easeInOutQuad'  => 'easeInOutQuad',
            'easeInCubic'  => 'easeInCubic',
            'easeOutCubic'  => 'easeOutCubic',
            'easeInOutCubic'  => 'easeInOutCubic',
            'easeInQuart'  => 'easeInQuart',
            'easeOutQuart'  => 'easeOutQuart',
            'easeInOutQuart'  => 'easeInOutQuart',
            'easeInQuint'  => 'easeInQuint',
            'easeOutQuint'  => 'easeOutQuint',
            'easeInOutQuint'  => 'easeInOutQuint',
            'easeInExpo'  => 'easeInExpo',
            'easeOutExpo'  => 'easeOutExpo',
            'easeInOutExpo'  => 'easeInOutExpo',
            'easeInSine'  => 'easeInSine',
            'easeOutSine'  => 'easeOutSine',
            'easeInOutSine'  => 'easeInOutSine',
            'easeInCirc'  => 'easeInCirc',
            'easeOutCirc'  => 'easeOutCirc',
            'easeInBack'  => 'easeInBack',
            'easeOutBack'  => 'easeOutBack',
            'easeInOutBack'  => 'easeInOutBack',
        ),
        '#default_value'    => theme_get_setting('header_slide_effect') ? theme_get_setting('header_slide_effect') : 'fade',
        '#description' => 'Visit '.l('here','http://jqueryui.com/resources/demos/effect/easing.html').' for more detail. Some effect are removed for better display reason.',
    );

    $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd-vd-slide-wrapper" class="hd-vd-slide-wrapper"><h3>Header Video Slide Content</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('hd_slide_max_num') ? theme_get_setting('hd_slide_max_num') : 1;
    $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="hd_slide_preview" data-max-num="'.$max_num.'" href="#hd-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('hd_slide_max_num') ? theme_get_setting('hd_slide_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']["hd_slide_preview_openhtml"] = array(
        '#markup'   => '<ul id="hd_slide_sortable" class="sortable">'
    );
    if(theme_get_setting('hd_slide') && count(theme_get_setting('hd_slide')) > 1) {
        $hd_slide = theme_get_setting('hd_slide');
        foreach($hd_slide as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="hd-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="hd-slide-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key]['hd_slide_image_path_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => t('Path to custom background image'),
                '#default_value' =>  $hd_slide[$key]['image'],
                '#prefix' => '<div>',
                '#maxlength' => 1000,
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key]['hd_slide_image_upload_'.$num.''] = array(
                '#type' => 'file',
                '#suffix' => '</div>'
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key]['hd_slide_before_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Before Title',
                '#default_value'    => $hd_slide[$key]['before_title'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key]['hd_slide_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Title',
                '#default_value'    => $hd_slide[$key]['title'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key]['hd_slide_des_'.$num] = array(
                '#type' => 'textarea',
                '#title'    => 'Description',
                '#resizable'    => FALSE,
                '#default_value'    => $hd_slide[$key]['des'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key]['hd_slide_button_text_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Button Text',
                '#default_value'    => $hd_slide[$key]['button_text'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key]['hd_slide_button_text_hover_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Button Text Hover',
                '#default_value'    => $hd_slide[$key]['button_text_hover'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key]['hd_slide_button_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Button Link',
                '#default_value'    => $hd_slide[$key]['button_link'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="hd-slide-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="hd-slide-sortable-no1">'
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_image_path_no1'] = array(
            '#type' => 'textfield',
            '#title' => t('Path to custom background image'),
            '#default_value' =>  theme_get_setting('hd_slide_image_path_no1'),
            '#prefix' => '<div>',
            '#maxlength' => 1000,
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_image_upload_no1'] = array(
            '#type' => 'file',
            '#suffix' => '</div>'
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_before_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Before Title',
            '#default_value'    => theme_get_setting('hd_slide_before_title_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Title',
            '#resizable'    => FALSE,
            '#default_value'    => theme_get_setting('hd_slide_title_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_des_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Description',
            '#resizable'    => FALSE,
            '#default_value'    => theme_get_setting('hd_slide_des_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_button_text_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Button Text',
            '#default_value'    => theme_get_setting('hd_slide_button_text_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_button_text_hover_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Button Text Hover',
            '#default_value'    => theme_get_setting('hd_slide_button_text_hover_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_button_link_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Button Link',
            '#default_value'    => theme_get_setting('hd_slide_button_link_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']['hd_slide_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_alpine_settings']['design']['design_header']['header_content']['hd_slide_content_wrapper']['hd_slide_preview']["hd_slide_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );

    /* ============================================= Header Pattern ===========================================*/

    $form['md_alpine_settings']['design']['design_header']['header_pattern'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="header-pattern-wrapper"><h2>Custom Pattern Slider</h2>',
        "#suffix"   => '</div>',
    );
    // Pattern Slider
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['header_pt_slide_auto'] = array(
        '#type' => 'checkbox',
        '#title'    => 'Pattern Slide Autoplay',
        '#default_value'   => theme_get_setting('header_pt_slide_auto')
    );
    $items = array();
    $path_data_dir = drupal_get_path('theme', 'md_alpine') . '/images/background/patterns';
    $files = file_scan_directory($path_data_dir, '/.png$/');
    $pattern_css = "";
    foreach ($files as $file) {
        $items[$file->name] = t('Pattern ' . $file->name);
        $pattern_css .= '#hd'.$file->name.' {background:url(' . $base_url .'/'. drupal_get_path('theme', 'md_alpine') . '/images/background/patterns/' . $file->name . '.png) repeat 0 0;}';
    }
    drupal_add_css($pattern_css, 'inline');

    $form['md_alpine_settings']['design']['design_header']['header_pattern']['choose_header_pt_pattern'] = array(
        '#type'          => 'select',
        '#title'         => t('Choose Pattern'),
        '#default_value' => theme_get_setting('choose_header_pt_pattern'),
        '#options'       => $items,
        '#prefix' => '<div id="design-hd-bg-pattern" class="clearfix">',
        '#suffix' => '</div>',
    );
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd-pt-slide-wrapper" class="hd-pt-slide-wrapper"><h3>Header Pattern Slide Content</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('hd_pt_slide_max_num') ? theme_get_setting('hd_pt_slide_max_num') : 1;
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="hd_pt_slide_preview" data-max-num="'.$max_num.'" href="#hd-pt-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd__pt_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd_pt_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('hd_pt_slide_max_num') ? theme_get_setting('hd_pt_slide_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']["hd_pt_slide_preview_openhtml"] = array(
        '#markup'   => '<ul id="hd_pt_slide_sortable" class="sortable">'
    );
    if(theme_get_setting('hd_pt_slide') && count(theme_get_setting('hd_pt_slide')) > 1) {
        $hd_pt_slide = theme_get_setting('hd_pt_slide');
        foreach($hd_pt_slide as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="hd-pt-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="hd-pt-slide-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview'][$key]['hd_pt_slide_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Title',
                '#default_value'    => $hd_pt_slide[$key]['title'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview'][$key]['hd_pt_slide_des_'.$num] = array(
                '#type' => 'textarea',
                '#title'    => 'Description',
                '#resizable'    => FALSE,
                '#default_value'    => $hd_pt_slide[$key]['des'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview'][$key]['hd_pt_slide_button_text_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Button Text',
                '#default_value'    => $hd_pt_slide[$key]['button_text'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview'][$key]['hd_pt_slide_button_text_hover_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Button Text Hover',
                '#default_value'    => $hd_pt_slide[$key]['button_text_hover'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview'][$key]['hd_pt_slide_button_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Button Link',
                '#default_value'    => $hd_pt_slide[$key]['button_link'],
            );
            $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']['hd_pt_slide_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="hd-pt-slide-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="hd-pt-slide-sortable-no1">'
        );
        $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']['hd_pt_slide_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Title',
            '#default_value'    => theme_get_setting('hd_pt_slide_title_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']['hd_pt_slide_des_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Description',
            '#resizable'    => FALSE,
            '#default_value'    => theme_get_setting('hd_pt_slide_des_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']['hd_pt_slide_button_text_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Button Text',
            '#default_value'    => theme_get_setting('hd_pt_slide_button_text_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']['hd_pt_slide_button_text_hover_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Button Text Hover',
            '#default_value'    => theme_get_setting('hd_pt_slide_button_text_hover_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']['hd_pt_slide_button_link_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Button Link',
            '#default_value'    => theme_get_setting('hd_pt_slide_button_link_no1')
        );
        $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']['hd_pt_slide_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_alpine_settings']['design']['design_header']['header_pattern']['hd_pt_slide_content_wrapper']['hd_pt_slide_preview']["hd_pt_slide_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );

    /* 3.	Parallax
    --------------------------------------------------------------------------*/
    $form['md_alpine_settings']['design']['design_parallax'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -7,
        '#prefix'  				=> '<div id="ds-parallax" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_htmllist'] = array(
        '#markup' 				=> '<div id="md-subtabs" class="md-subtabs">
								<div class="md-subtabs-head">
		              <ul class="clearfix">
		                <li class="subtab-item clearfix first"> <a class="subtab-link" href="#parallax-1-form">Parallax 1</a> </li>
		                <li class="subtab-item clearfix"> <a class="subtab-link" href="#parallax-2-form">Parallax 2</a> </li>
		                <li class="subtab-item clearfix last"> <a class="subtab-link" href="#parallax-3-form">Parallax 3</a> </li>
		                <li class="subtab-item clearfix last"> <a class="subtab-link" href="#parallax-4-form">Parallax 4</a> </li>
		                <li class="subtab-item clearfix last"> <a class="subtab-link" href="#parallax-5-form">Parallax 5</a> </li>
		                <li class="subtab-item clearfix last"> <a class="subtab-link" href="#parallax-6-form">Parallax 6</a> </li>
		                <li class="subtab-item clearfix last"> <a class="subtab-link" href="#parallax-7-form">Parallax 7</a> </li>
		              </ul>
		            </div>',
        '#weight' 				=> -15,
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_htmllistclose'] = array(
        '#markup' 				=> '</div><!-- /#sub-tab -->',
        '#weight' 				=> 15,
    );
    for($i=1;$i<=7;$i++){
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.''] = array(
            '#type'             => 'fieldset',
            '#title'            => t('<h2>Parallax '.$i.'</h2>'),
            '#description'      => t(''),
            '#prefix'  				=> '<div id="parallax-'.$i.'-form" class="md-subtabcontent clearfix">',
            '#suffix'        => '</div><!-- / #parallax-1 -->',
        );

        md_alpine_prepare_parallax_form($form,$i);
    }



   // 4. ---------------------------------- Footer --------------------------------------------
    $form['md_alpine_settings']['design']['design_footer'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -8,
        '#prefix'  				=> '<div id="ds-footer" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_alpine_settings']['design']['design_footer']['footer_social'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="footer-social"><h3>Custom Social Account</h3>',
        '#suffix'   => '</div>',
    );
    $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft-social-acc-wrapper">',
        '#suffix'   => '</div>',
        '#attributes'   => array(
            'class' => array('ft-social-acc-wrapper'),
        )
    );
    $max_num = theme_get_setting('ft_social_max_num') ? theme_get_setting('ft_social_max_num') : 1;
    $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="ft_social_preview" data-max-num="'.$max_num.'" href="#ft-social-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft_social_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']['ft_social_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']['ft_social_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('ft_social_max_num') ? theme_get_setting('ft_social_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']["ft_social_preview_openhtml"] = array(
        '#markup'   => '<ul id="ft_social_sortable" class="sortable">'
    );
    if(theme_get_setting('ft_social') && count(theme_get_setting('ft_social')) > 1) {
        $social_acc = theme_get_setting('ft_social');
        foreach(theme_get_setting('ft_social') as $key => $value){
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $social_icon = $social_acc[$key]['icon'];
            $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="ft-social-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="ft-social-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key]['ft_social_icon_'.$num] = array(
                '#type' => 'icon_selector',
                '#title'    => 'Social Icon',
                '#default_bundle' => isset($social_icon['bundle']) ? $social_icon['bundle'] : '',
                '#default_icon' => $social_icon['icon'],
                '#attributes'   => array(
                    'class' => array('icon-select'),
                    'id'    => array('footer-social-'.$num.'')
                )
            );

            $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key]['ft_social_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Social Link',
                '#attributes' => array(
                    'class' => array('social_link'),
                ),
                '#default_value' => $social_acc[$key]['link'],
                '#maxlength' => 1000,
            );
            $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $social_icon_1 = theme_get_setting('ft_social_icon_1');
        $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key.'_openhtml'] = array(
            '#markup' => '<li id="ft-social-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="ft-social-sortable-no1">'
        );
        $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']['ft_social_icon_no1'] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Social Icon',
            '#default_bundle' => isset($social_icon_1['bundle']) ? $social_icon_1['bundle'] : '',
            '#default_icon' => $social_icon_1['icon'],
            '#attributes'   => array(
                'class' => array('icon-select'),
                'id'    => array('footer-social-no1')
            )
        );

        $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']['ft_social_link_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Social Link',
            '#attributes' => array(
                'class' => array('ft_social_link'),
            ),
            '#default_value' => theme_get_setting('ft_social_link_no1'),
            '#maxlength' => 1000,
        );
        $form['md_alpine_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key.'_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }

    $form['md_alpine_settings']['design']['design_footer']['footer_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft-content-wrapper">',
        '#suffix'   => '</div>'
    );
    $form['md_alpine_settings']['design']['design_footer']['footer_content_wrapper']['footer_text'] = array(
        '#type' => 'textarea',
        '#title'    => 'Footer Text Display',
        '#resizable'    => false,
        '#default_value'    => theme_get_setting('footer_text') ? theme_get_setting('footer_text') : '© Copyright 2013 by Alpine Studios. All Rights Reserved. Powered by <a href="http://www.creative-ispiration.com"> <strong>creative-ispiration.com</strong> </a>'
    );
    /* 5.
       --------------------------------- 404 Page -------------------------------------------*/
    $form['md_alpine_settings']['design']['design_team'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -9,
        '#prefix'  				=> '<div id="ds-team" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    $form['md_alpine_settings']['design']['design_team']['team_image_path'] = array(
        '#type' => 'textfield',
        '#title' => t('Path to custom team image'),
        '#default_value' =>  theme_get_setting('team_image_path'),
        '#prefix' => '<div>',
        '#maxlength' => 1000,
    );
    $form['md_alpine_settings']['design']['design_team']['team_image_upload'] = array(
        '#type' => 'file',
        '#suffix' => '</div>'
    );
    /* 6.
    --------------------------------- 404 Page -------------------------------------------*/
    $form['md_alpine_settings']['design']['design_nf'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -9,
        '#prefix'  				=> '<div id="ds-nf" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    $form['md_alpine_settings']['design']['design_nf']['nf_pattern_bg'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="nf-pattern-bg" class="nf-pattern-bg">',
        '#suffix' => '</div>',
    );
    $items = array();
    $path_data_dir = drupal_get_path('theme', 'md_alpine') . '/images/background/patterns';
    $files = file_scan_directory($path_data_dir, '/.png$/');
    $pattern_css = "";
    foreach ($files as $file) {
        $items[$file->name] = t('Pattern ' . $file->name);
        $pattern_css .= '#nf'.$file->name.' {background:url(' . $base_url .'/'. drupal_get_path('theme', 'md_alpine') . '/images/background/patterns/' . $file->name . '.png) repeat 0 0;}';
    }
    drupal_add_css($pattern_css, 'inline');


    $form['md_alpine_settings']['design']['design_nf']['nf_pattern_bg']['choose_nf_pattern'] = array(
        '#type'          => 'select',
        '#title'         => t('Choose Pattern'),
        '#default_value' => theme_get_setting('choose_nf_pattern'),
        '#options'       => $items,
        '#prefix' => '<div id="design-nf-bg-pattern" class="clearfix">',
        '#suffix' => '</div>',
    );
    $form['md_alpine_settings']['design']['design_nf']['nf_content'] = array(
        '#type' => 'fieldset',
        '#title'    => '<h3>404 Content</h3>'
    );
    $form['md_alpine_settings']['design']['design_nf']['nf_content']['nf_text'] = array(
        '#type' => 'textfield',
        '#title'    => '404 Text Display',
        '#default_value' => theme_get_setting('nf_text') ? theme_get_setting('nf_text') : "404<i>Page not found</i>",
    );
    $form['md_alpine_settings']['design']['design_nf']['nf_content']['nf_des'] = array(
        '#type' => 'textfield',
        '#title'    => '404 Description',
        '#default_value' => theme_get_setting('nf_des') ? theme_get_setting('nf_des') : "Sorry, the page you are looking for does not exist.",
    );
}



function md_alpine_prepare_parallax_form(&$form, $i) {
    global $base_url;
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_enabled'] = array(
        '#type'             => 'checkbox',
        '#title'            => t('Enable Parallax '.$i.''),
        '#default_value'    => theme_get_setting('parallax_'.$i.'_enabled'),
        '#suffix'           => '<div id="parallax-'.$i.'-custom">',
        '#attributes'   => array(
            'class' => array('enable-parallax'),
        )
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_title'] = array(
        '#type' => 'textfield',
        '#title' => 'Parallax '.$i.' Title',
        '#default_value'    => theme_get_setting('pr_'.$i.'_title') ? theme_get_setting('pr_'.$i.'_title') : '',
        '#max_length'   => 1000,
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_des'] = array(
        '#type' => 'textfield',
        '#title' => 'Parallax '.$i.' Description',
        '#max_length'   => 1000,
        '#default_value'    => theme_get_setting('pr_'.$i.'_des') ? theme_get_setting('pr_'.$i.'_des') : ''
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_bg_image_path'] = array(
        '#type' => 'textfield',
        '#title' => t('Path to custom background image'),
        '#default_value' =>  theme_get_setting('pr_'.$i.'_bg_image_path'),
        '#maxlength' => 1000,
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_bg_image_upload'] = array(
        '#type' => 'file',
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overlay_enable'] = array(
        '#type' => 'checkbox',
        '#title'    => 'Enable Parallax '.$i.' Overlay',
        '#attributes'   => array(
            'class' => array('enable-overlay')
        ),
        '#default_value'    => theme_get_setting('pr_'.$i.'_overlay_enable')
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overlay_settings'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-overlay-settings">',
        '#suffix'   => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overlay_settings']['pr_'.$i.'_overlay_color'] = array(
        '#type'          	=> 'textfield',
        '#title'         	=> t('Overlay Color'),
        '#default_value' 	=> theme_get_setting('pr_'.$i.'_overlay_color'),
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>',
        '#attributes' 		=> array(
            'class' => array(
                'form-colorpicker',
            ),
        ),
    );
    drupal_add_js(array('pr'.$i.'Opacity' => theme_get_setting('pr_'.$i.'_overlay_opacity')),'setting');
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overlay_settings']['pr_'.$i.'_overlay_opacity'] = array(
        '#type' => 'hidden',
        '#prefix'   => '<label>Overlay Opacity</label><div id="pr-'.$i.'-overlay-opacity" class="pr-overlay-opacity">',
        '#suffix'   => '</div>',
        '#attributes'   => array(
            'class' => array('opacity-value')
        ),
        '#default_value'    => theme_get_setting('pr_'.$i.'_overlay_opacity')
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_type'] = array(
        '#type' => 'select',
        '#title'    => 'Choose Parallax type',
        '#options'  => array(
            'skills'    => 'Skills(Charts)',
            'connect'    => 'Social Connect',
            'button' => 'Single Button',
            'number'     => 'Number(jQuery countTo)',
            'customer'   => 'Customer',
            'overview' => 'Overview',
            'contact' => 'Contact',
        ),
        '#default_value'    => theme_get_setting('parallax_'.$i.'_type'),
        '#attributes'   => array(
            'class' => array('pr-type')
        )
    );
    /* ----------------------------------------------    Parallax Skills   ---------------------------------------------------- */

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-skills-wrapper" class="pr-skill-wrapper"><h3>Your Skills</h3>',
        '#suffix'   => '</div>'
    );

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div class="content-wrapper"><h3>Parallax Content</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('pr_'.$i.'_skills_max_num') ? theme_get_setting('pr_'.$i.'_skills_max_num') : 1;
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="pr_'.$i.'_skills_preview" data-max-num="'.$max_num.'" href="#pr-'.$i.'-skill-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr_'.$i.'_skills_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skill_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('pr_'.$i.'_skills_max_num') ? theme_get_setting('pr_'.$i.'_skills_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview']["pr_'.$i.'_skills_preview_openhtml"] = array(
        '#markup'   => '<ul id="pr_'.$i.'_skills_sortable" class="sortable">'
    );
    if(theme_get_setting('pr_'.$i.'_skill') && count(theme_get_setting('pr_'.$i.'_skill')) > 1) {
        $skills = theme_get_setting('pr_'.$i.'_skill');
        foreach($skills as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="pr-'.$i.'-skill-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="pr-'.$i.'-skill-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview'][$key]['pr_'.$i.'_skill_percent_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Skill Percent',
                '#default_value'    => $skills[$key]['percent'],
                '#prefix'   => '<div class="form-item-circle">',
                '#suffix'   => '</div>',
                '#element_validate' => array('element_validate_integer_positive'),
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview'][$key]['pr_'.$i.'_skill_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Skill Title',
                '#resizable'    => FALSE,
                '#default_value'    => $skills[$key]['title']
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview'][$key]['pr_'.$i.'_skill_des_'.$num] = array(
                '#type' => 'textarea',
                '#title'    => 'Skill Description',
                '#default_value'    => $skills[$key]['des']
            );

            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview']['pr_'.$i.'_skill_hidden_no1_openhtml'] = array(
            '#markup' => '<li id="pr-'.$i.'-skill-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="pr-'.$i.'-skill-sortable-no1">'
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview']['pr_'.$i.'_skill_percent_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Skill Percent',
            '#default_value'    => theme_get_setting('pr_'.$i.'_skill_percent_no1'),
            '#element_validate' => array('element_validate_integer_positive'),
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview']['pr_'.$i.'_skill_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Skill Title',
            '#default_value'    => theme_get_setting('pr_'.$i.'_skill_title_no1'),

        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview']['pr_'.$i.'_skill_des_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Skill Description',
            '#resizable'    => FALSE,
            '#default_value'    => theme_get_setting('pr_'.$i.'_skill_des_no1')
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview']['pr_'.$i.'_skill_hidden_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_skills']['pr_'.$i.'_skills_content_wrapper']['pr_'.$i.'_skills_preview']["pr_'.$i.'_skills_preview_closehtml"] = array(
        '#markup'   => '</ul>',
    );
    /* --------------------------------------------------Parallax Social Connect -----------------------------------------------------*/
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-connect-wrapper" class="pr-connect-wrapper"><h3>Your connect</h3>',
        '#suffix'   => '</div>'
    );

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div class="content-wrapper"><h3>Parallax Content</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('pr_'.$i.'_connect_max_num') ? theme_get_setting('pr_'.$i.'_connect_max_num') : 1;
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="pr_'.$i.'_connect_preview" data-max-num="'.$max_num.'" href="#pr-'.$i.'-connect-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr_'.$i.'_connect_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('pr_'.$i.'_connect_max_num') ? theme_get_setting('pr_'.$i.'_connect_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview']["pr_'.$i.'_connect_preview_openhtml"] = array(
        '#markup'   => '<ul id="pr_'.$i.'_connect_sortable" class="sortable">'
    );
    if(theme_get_setting('pr_'.$i.'_connect') && count(theme_get_setting('pr_'.$i.'_connect')) > 1) {
        $connect = theme_get_setting('pr_'.$i.'_connect');
        foreach($connect as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            if(isset($connect[$key]['icon'])){
                $connect_icon = $connect[$key]['icon'];
            }

            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="pr-'.$i.'-connect-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="pr-'.$i.'-connect-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview'][$key]['pr_'.$i.'_connect_icon_'.$num] = array(
                '#type' => 'icon_selector',
                '#title'    => 'Social Connect Icon',
                '#default_bundle' => isset($connect_icon['bundle']) ? $connect_icon['bundle'] : '',
                '#default_icon' => isset($connect_icon['icon']) ? $connect_icon['icon'] : '',
                '#attributes'   => array(
                    'class' => array('icon-select'),
                    'id'    => array('pr-'.$i.'-connect-fake-'.$num.''),
                ),
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview'][$key]['pr_'.$i.'_connect_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Social Connect Icon Link',
                '#default_value'    => $connect[$key]['link'],
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview'][$key]['pr_'.$i.'_connect_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Social Connect Title',
                '#default_value'    => $connect[$key]['title'],
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview'][$key]['pr_'.$i.'_connect_des_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Social Connect Description',
                '#default_value'    => $connect[$key]['des'],
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview']['pr_'.$i.'_connect_hidden_no1_openhtml'] = array(
            '#markup' => '<li id="pr-'.$i.'-connect-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="pr-'.$i.'-connect-sortable-no1">'
        );
        $connect_icon_no1 = theme_get_setting('pr_'.$i.'_connect_icon_no1');
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview']['pr_'.$i.'_connect_icon_no1'] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Social Connect Icon',
            '#default_bundle' => isset($connect_icon_no1['bundle']) ? $connect_icon_no1['bundle'] : '',
            '#default_icon' => $connect_icon_no1['icon'],
            '#attributes'   => array(
                'class' => array('icon-select'),
                'id'    => array('pr-'.$i.'-connect-fake-no1'),
            ),
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview']['pr_'.$i.'_connect_link_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Social Connect Icon Link',
            '#default_value'    => theme_get_setting('pr_'.$i.'_connect_link_no1'),
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview']['pr_'.$i.'_connect_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Social Connect Title',
            '#default_value'    => theme_get_setting('pr_'.$i.'_connect_title_no1'),

        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview']['pr_'.$i.'_connect_des_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Social Connect Description',
            '#default_value'    => theme_get_setting('pr_'.$i.'_connect_des_no1')
        );

        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview']['pr_'.$i.'_connect_hidden_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_connect']['pr_'.$i.'_connect_content_wrapper']['pr_'.$i.'_connect_preview']["pr_'.$i.'_connect_preview_closehtml"] = array(
        '#markup'   => '</ul>',
    );


    /* ---------------------------------------------- Parallax Number (Using jquery CountTO) ----------------------------------------------------*/
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-number-wrapper" class="pr-number-wrapper"><h3>Your number</h3>',
        '#suffix'   => '</div>'
    );

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div class="content-wrapper"><h3>Parallax Content</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('pr_'.$i.'_number_max_num') ? theme_get_setting('pr_'.$i.'_number_max_num') : 1;
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="pr_'.$i.'_number_preview" data-max-num="'.$max_num.'" href="#pr-'.$i.'-number-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr_'.$i.'_number_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('pr_'.$i.'_number_max_num') ? theme_get_setting('pr_'.$i.'_number_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview']["pr_'.$i.'_number_preview_openhtml"] = array(
        '#markup'   => '<ul id="pr_'.$i.'_number_sortable" class="sortable">'
    );
    if(theme_get_setting('pr_'.$i.'_number') && count(theme_get_setting('pr_'.$i.'_number')) > 1) {
        $number = theme_get_setting('pr_'.$i.'_number');
        foreach($number as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            if(isset($number[$key]['icon'])){
                $number_icon = $number[$key]['icon'];
            }
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="pr-'.$i.'-number-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="pr-'.$i.'-number-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview'][$key]['pr_'.$i.'_number_icon_'.$num] = array(
                '#type' => 'icon_selector',
                '#title'    => 'Icon',
                '#default_bundle' => isset($number_icon['bundle']) ? $number_icon['bundle'] : '',
                '#default_icon' => isset($number_icon['icon']) ? $number_icon['icon'] : '',
                '#attributes'   => array(
                    'class' => array('icon-select'),
                    'id'    => array('pr-'.$i.'-number-fake-'.$num.''),
                ),
                '#prefix' => '<div>',
                '#suffix' => '</div>',
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview'][$key]['pr_'.$i.'_number_count_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Count Number From',
                '#default_value'    => isset($number[$key]['number_count']) ? $number[$key]['number_count'] : '',
                '#element_validate' => array('element_validate_integer_positive'),
                '#prefix' => '<div>',
                '#suffix' => '</div>',
            );

            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview'][$key]['pr_'.$i.'_number_des_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Description',
                '#default_value'    => isset($number[$key]['des']) ? $number[$key]['des'] : '',
                '#prefix' => '<div>',
                '#suffix' => '</div>',
            );

            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview']['pr_'.$i.'_number_hidden_no1_openhtml'] = array(
            '#markup' => '<li id="pr-'.$i.'-number-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="pr-'.$i.'-number-sortable-no1">'
        );
        $number_icon_no1 = theme_get_setting('pr_'.$i.'_number_icon_no1');
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview']['pr_'.$i.'_number_icon_no1'] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Icon',
            '#default_bundle' => isset($number_icon_no1['bundle']) ? $number_icon_no1['bundle'] : '',
            '#default_icon' => $number_icon_no1['icon'],
            '#attributes'   => array(
                'class' => array('icon-select'),
                'id'    => array('pr-'.$i.'-number-fake-no1'),
            ),
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview']['pr_'.$i.'_number_count_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Count Number',
            '#default_value'    => theme_get_setting('pr_'.$i.'_number_count_no1'),
            '#element_validate' => array('element_validate_integer_positive'),
        );

        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview']['pr_'.$i.'_number_des_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Description',
            '#default_value'    => theme_get_setting('pr_'.$i.'_number_des_no1'),
        );

        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview']['pr_'.$i.'_number_hidden_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_number']['pr_'.$i.'_number_content_wrapper']['pr_'.$i.'_number_preview']["pr_'.$i.'_number_preview_closehtml"] = array(
        '#markup'   => '</ul>',
    );
    /*---------------------------------------- Parallax Single Button -------------------------------------------*/
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_button'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-button-wrapper" class="pr-button-wrapper"><h3>Your Button Introduce</h3>',
        '#suffix'   => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_button']['pr_'.$i.'_button_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Button Text',
        '#default_value'    => theme_get_setting('pr_'.$i.'_button_text'),
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_button']['pr_'.$i.'_button_text_hover'] = array(
        '#type' => 'textfield',
        '#title'    => 'Button Text Hover',
        '#default_value'    => theme_get_setting('pr_'.$i.'_button_text_hover'),
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_button']['pr_'.$i.'_button_link'] = array(
        '#type' => 'textfield',
        '#title'    => 'Button Link',
        '#default_value'    => theme_get_setting('pr_'.$i.'_button_link'),
        '#max_length'   => 1000
    );
    /*---------------------------------------- Parallax Customer ----------------------------------------*/

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-customer-wrapper" class="pr-customer-wrapper"><h3>Your customer</h3>',
        '#suffix'   => '</div>'
    );

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div class="content-wrapper"><h3>Parallax Content</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('pr_'.$i.'_customer_max_num') ? theme_get_setting('pr_'.$i.'_customer_max_num') : 1;
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="pr_'.$i.'_customer_preview" data-max-num="'.$max_num.'" href="#pr-'.$i.'-customer-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr_'.$i.'_customer_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('pr_'.$i.'_customer_max_num') ? theme_get_setting('pr_'.$i.'_customer_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview']["pr_'.$i.'_customer_preview_openhtml"] = array(
        '#markup'   => '<ul id="pr_'.$i.'_customer_sortable" class="sortable">'
    );

    if(theme_get_setting('pr_'.$i.'_customer') && count(theme_get_setting('pr_'.$i.'_customer')) > 1) {
        $customer = theme_get_setting('pr_'.$i.'_customer');
        foreach($customer as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="pr-'.$i.'-customer-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="pr-'.$i.'-customer-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview'][$key]['pr_'.$i.'_customer_image_path_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => t('Path to custom background image'),
                '#default_value' =>  $customer[$key]['image'],
                '#prefix' => '<div class="md-updateimage">',
                '#maxlength' => 10000,
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview'][$key]['pr_'.$i.'_customer_image_upload_'.$num.''] = array(
                '#type' => 'file',
                '#suffix' => '</div>'
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview'][$key]['pr_'.$i.'_customer_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Customer Link',
                '#default_value'    => $customer[$key]['link'],
                '#prefix' => '<div>',
                '#suffix' => '</div>',
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview']['pr_'.$i.'_customer_hidden_no1_openhtml'] = array(
            '#markup' => '<li id="pr-'.$i.'-customer-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="pr-'.$i.'-customer-sortable-no1">'
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview']['pr_'.$i.'_customer_image_path_no1'] = array(
            '#type' => 'textfield',
            '#title' => t('Path to custom background image'),
            '#default_value' => theme_get_setting('pr_'.$i.'_customer_image_path_no1'),
            '#prefix' => '<div class="md-updateimage">',
            '#maxlength' => 10000,
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview']['pr_'.$i.'_customer_image_upload_no1'] = array(
            '#type' => 'file',
            '#suffix' => '</div>'

        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview']['pr_'.$i.'_customer_link_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Customer Link',
            '#default_value'    => theme_get_setting('pr_'.$i.'_customer_link_no1'),
            '#prefix' => '<div>',
            '#suffix' => '</div>',
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview']['pr_'.$i.'_customer_hidden_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_customer']['pr_'.$i.'_customer_content_wrapper']['pr_'.$i.'_customer_preview']["pr_'.$i.'_customer_preview_closehtml"] = array(
        '#markup'   => '</ul>',
    );
    /* ------------------------------------------------------ Parallax Overview --------------------------------------------------------*/

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-overview-wrapper" class="pr-overview-wrapper"><h3>Your overview</h3>',
        '#suffix'   => '</div>'
    );

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div class="content-wrapper"><h3>Parallax Content</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('pr_'.$i.'_overview_max_num') ? theme_get_setting('pr_'.$i.'_overview_max_num') : 1;
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="pr_'.$i.'_overview_preview" data-max-num="'.$max_num.'" href="#pr-'.$i.'-overview-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr_'.$i.'_overview_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('pr_'.$i.'_overview_max_num') ? theme_get_setting('pr_'.$i.'_overview_max_num') : 1,
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview']["pr_'.$i.'_overview_preview_openhtml"] = array(
        '#markup'   => '<ul id="pr_'.$i.'_overview_sortable" class="sortable">'
    );
    if(theme_get_setting('pr_'.$i.'_overview') && count(theme_get_setting('pr_'.$i.'_overview')) > 1) {
        $overview = theme_get_setting('pr_'.$i.'_overview');
        foreach($overview as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $overview_icon = $overview[$key]['icon'];
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="pr-'.$i.'-overview-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="pr-'.$i.'-overview-sortable-no'.substr($num,2).'">'
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview'][$key]['pr_'.$i.'_overview_icon_'.$num] = array(
                '#type' => 'icon_selector',
                '#title'    => 'Overview Icon',
                '#default_bundle' => isset($overview_icon['bundle']) ? $overview_icon['bundle'] : '',
                '#default_icon' => $overview_icon['icon'],
                '#attributes'   => array(
                    'class' => array('icon-select'),
                    'id'    => array('pr-'.$i.'-overview-fake-'.$num.''),
                ),
                '#prefix' => '<div>',
                '#suffix' => '</div>',
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview'][$key]['pr_'.$i.'_overview_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Overview Title',
                '#default_value'    => $overview[$key]['title'],
                '#prefix' => '<div>',
                '#suffix' => '</div>',
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview'][$key]['pr_'.$i.'_overview_des_'.$num] = array(
                '#type' => 'textarea',
                '#title'    => 'Overview Description',
                '#default_value'    => $overview[$key]['des'],
                '#resizable' => false,
                '#prefix' => '<div>',
                '#suffix' => '</div>',
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview'][$key]['pr_'.$i.'_overview_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Overview Link',
                '#default_value'    => $overview[$key]['link'],
                '#prefix' => '<div>',
                '#suffix' => '</div>',
            );
            $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview']['pr_'.$i.'_overview_hidden_no1_openhtml'] = array(
            '#markup' => '<li id="pr-'.$i.'-overview-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="pr-'.$i.'-overview-sortable-no1">'
        );
        $overview_icon_no1 = theme_get_setting('pr_'.$i.'_overview_icon_no1');
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview']['pr_'.$i.'_overview_icon_no1'] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Overview Icon',
            '#default_bundle' => isset($overview_icon_no1['bundle']) ? $overview_icon_no1['bundle'] : '',
            '#default_icon' => $overview_icon_no1['icon'],
            '#attributes'   => array(
                'class' => array('icon-select'),
                'id'    => array('pr-'.$i.'-overview-fake-no1'),
            ),
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview']['pr_'.$i.'_overview_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Overview Title',
            '#default_value'    => theme_get_setting('pr_'.$i.'_overview_title_no1'),

        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview']['pr_'.$i.'_overview_des_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Overview Description',
            '#resizable' => FALSE,
            '#default_value'    => theme_get_setting('pr_'.$i.'_overview_des_no1')
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview']['pr_'.$i.'_overview_link_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Overview Link',
            '#default_value'    => theme_get_setting('pr_'.$i.'_overview_link_no1'),
            '#prefix' => '<div>',
            '#suffix' => '</div>',
        );
        $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview']['pr_'.$i.'_overview_hidden_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><input class="edit form-submit" value="Edit"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_overview']['pr_'.$i.'_overview_content_wrapper']['pr_'.$i.'_overview_preview']["pr_'.$i.'_overview_preview_closehtml"] = array(
        '#markup'   => '</ul>',
    );

    /* ---------------------------------------------------- Parallax Contact -----------------------------------------------*/

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_contact'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-contact-wrapper" class="pr-contact-wrapper"><h3>Your contact</h3>',
        '#suffix'   => '</div>'
    );

    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_contact']['pr_'.$i.'_contact_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div class="content-wrapper"><h3>Parallax Content</h3>',
        '#suffix'   => '</div>'
    );
    $contact_icon_no1 = theme_get_setting('pr_'.$i.'_contact_icon_no1');
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_contact']['pr_'.$i.'_contact_content_wrapper']['pr_'.$i.'_contact_icon_no1'] = array(
        '#type' => 'icon_selector',
        '#title'    => 'Contact Icon',
        '#default_bundle' => isset($contact_icon_no1['bundle']) ? $contact_icon_no1['bundle'] : '',
        '#default_icon' => $contact_icon_no1['icon'],
        '#attributes'   => array(
            'class' => array('icon-select'),
            'id'    => array('pr-'.$i.'-contact-fake-no1'),
        ),
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_contact']['pr_'.$i.'_contact_content_wrapper']['pr_'.$i.'_contact_title_no1'] = array(
        '#type' => 'textfield',
        '#title'    => 'Contact Title',
        '#default_value'    => theme_get_setting('pr_'.$i.'_contact_title_no1'),

    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['pr_'.$i.'_contact']['pr_'.$i.'_contact_content_wrapper']['pr_'.$i.'_contact_des_no1'] = array(
        '#type' => 'textarea',
        '#title'    => 'Contact Description',
        '#resizable'    => FALSE,
        '#default_value'    => theme_get_setting('pr_'.$i.'_contact_des_no1')
    );
    $form['md_alpine_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_enable_close'] = array(
        '#markup' 	=> '</div>'
    );
}
function new_form_value($form,&$form_state){
    $form = array();
    for($i=1;$i<=7;$i++) {
        $form['pr_'.$i.''] = array(
            '#type' => 'fieldset',
        );
        $form['pr_'.$i.'']['pr_'.$i.'_skill_title'] = array(
            '#type' => 'textfield',
            '#title'    => 'Skill Title',
        );
        $form['pr_'.$i.'']['pr_'.$i.'_skill_des'] = array(
            '#type' => 'textfield',
            '#title'    => 'Skill Description',
        );
        $form['pr_'.$i.'']['pr_'.$i.'_skill_percent'] = array(
            '#type' => 'textfield',
            '#title'    => 'Skill Percent',
        );
    }
    return $form;
}