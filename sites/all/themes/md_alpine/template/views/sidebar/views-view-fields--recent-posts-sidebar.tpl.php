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
<div class="post-box">
    <?php if(isset($row->field_field_bl_thumbnail) && !empty($row->field_field_bl_thumbnail[0])) : ?>
    <a href="<?php print base_url().'/node/'.$row->nid;?>">
         <?php print '<img class="img-rounded" src="'.image_style_url('blog_sidebar_thumbnail',$row->field_field_bl_thumbnail[0]['rendered']['#item']['uri']).'" alt=""/>';?>
    </a>
    <?php endif;?>
    <div>
        <h5><a href="<?php print url(base_url().'/node/'.$row->nid);?>"><?php print $row->node_title;?></a></h5>
        <small><?php print date('F d, Y');?></small>
    </div>
</div>