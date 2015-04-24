<?php

/**
 * @file
 * Theme settings .
 */

function md_alpine_theme_settings_display(&$form, &$form_state) {
	$form['md_alpine_settings']['display'] = array(
		'#type' 					=> 'fieldset',
		'#weight' 				=> -1,
		'#prefix'  				=> '<div id="md-display" class="md-tabcontent clearfix">',
		'#suffix'        => '</div><!-- / #md-display -->',
	);

	$form['md_alpine_settings']['display']['display_htmllist'] = array(
		'#markup' 				=> '<div class="md-listleft">
				<ul>
					<li><a href="#s-map">Map</a></li>
				</ul>
			</div><div class="md-listcontent">',
		'#weight' 				=> -15,
	);

	$form['md_alpine_settings']['display']['display_htmllistclose'] = array(
		'#markup' 				=> '</div><!-- /.md-listleft -->',
		'#weight' 				=> 15,
	);

    $form['md_alpine_settings']['display']['map'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -8,
        '#prefix'  				=> '<div id="s-map" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #footer -->',
    );
    $form['md_alpine_settings']['display']['map']['map_marker_title'] = array(
        '#type' 					=> 'textfield',
        '#title'					=> t('Marker Title'),
        '#default_value' 	        =>  theme_get_setting('map_marker_title') ? theme_get_setting('map_marker_title') : t('Megadrupal'),
    );
    $form['md_alpine_settings']['display']['map']['map_marker_description'] = array(
        '#type' 					=> 'textarea',
        '#title'					=> t('Marker Description'),
        '#resizable'    => FALSE,
        '#default_value' 	        =>  theme_get_setting('map_marker_description') ? theme_get_setting('map_marker_description') : t('Ha Noi , Viet Nam, Asia'),
    );
    $form['md_alpine_settings']['display']['map']['map_latlng'] = array(
        '#type' 					=> 'textfield',
        '#title'					=> t('Google Map location'),
        '#default_value' 	        =>  theme_get_setting('map_latlng') ? theme_get_setting('map_latlng') : t('40.748395,-73.985542'),
        '#description'              =>  t('Find your map point by reading our documentation'),
    );
    $form['md_alpine_settings']['display']['map']['map_types']   = array(
        '#type'         => 'select',
        '#title'        => t('Map types'),
        '#options'      => array(
            'ROADMAP'  => t('Road Map'),
            'SATELINE' => t('Sate Line'),
            'HYBRID'    => t('Hybrid'),
            'TERRAIN'   => t('Terrain'),
        ),
        '#default_value'    => theme_get_setting('map_types') ? theme_get_setting('map_types') : t('ROADMAP'),
    );
    $form['md_alpine_settings']['display']['map']['map_zoom_level'] = array(
        '#type'         => 'textfield',
        '#title'        => t(' Map Zoom Level'),
        '#default_value'    => theme_get_setting('map_zoom_level') ? theme_get_setting('map_zoom_level') : 16,
    );
}