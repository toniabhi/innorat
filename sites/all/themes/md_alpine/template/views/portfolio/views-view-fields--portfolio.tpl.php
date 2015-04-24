<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php
    $multimedia = $row->field_field_multimedia;
    $icon_type = '';
    $portfolio_type = '';
    if(isset($multimedia) && count($multimedia) > 1 ) {
        $icon_type = $icon_type = '<i class="fontello icon-menu icon-4x"></i>';
        $portfolio_type  = t('Gallery Project');
    } else {
        if(isset($multimedia[0])) {
            $file_type = $multimedia[0]['rendered']['#file']->type;
            if($file_type == 'video') {
                $icon_type = '<i class="fontello icon-youtube-play icon-4x"></i>';
                $portfolio_type  = t('Video Project');
            }
            if($file_type == 'audio') {
                $icon_type = '<i class="fontello icon-music icon-4x"></i>';
                $portfolio_type  = t('Audio Project');
            }
            if($file_type == 'image') {
                $icon_type = '<i class="fontello icon-picture icon-4x"></i>';
                $portfolio_type  = t('Single Image');
            }
        }
    }
?>
<!-- portfolio item -->
<div class="portfolio-item <?php foreach($row->field_field_po_taxonomy as $key => $value): print 'tid-'.$value['raw']['tid'].' ';endforeach;?>">
    <div class="portfolio">
        <a href="#!?q=ajax_portfolio&nid=<?php print $row->nid;?>" data-nid="<?php print $row->nid;?>" class="zoom"> <img src="<?php print image_style_url('portfolio_thumbnails',$row->field_field_po_thumbnail[0]['rendered']['#item']['uri']);?>" alt="">
            <div class="hover-items">
                <span> <?php if($icon_type): print $icon_type; endif;?> <em class="lead"><?php print $fields['title']->content;?></em> <em><?php if($portfolio_type): print $portfolio_type; endif;?></em> </span>
            </div>
        </a>
    </div>
</div>
<!-- portfolio item -->