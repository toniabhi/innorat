<?php
/**
 * View preprocess
 */
function md_alpine_preprocess_views_view(&$vars) {
    $views = $vars['view'];
    if($views->disabled !== true){
        if($views->name == 'work'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $result = (object)$view['result'];
        }
        if($views->name == 'single_service'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $result = (object)$view['result'];
        }
        if($views->name == 'blog'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $result = (object)$view['result'];
        }
        if($views->name == 'contact'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $result = $view['result'];

            $vars['content_type_name'] = $view['type'];
            if(isset($result[0])) {
                $nid = $result[0]->nid;
                $node_object = node_load($nid);
                $webform = $node_object->webform;
                $components = $webform['components'];
                $field_webform_body = $view['field']['webform_form_body']->last_render;
                $vars['webform_content'] = $field_webform_body;
            }
        }
    }
}
