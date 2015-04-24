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
global $base_url;
$node = node_load($row->nid);
?>
<!-- Timeline item -->
<li class="timeline-item">
    <div class="item_left">
        <div class="well post">
            <div class="post-info bgdark text-center">
                <h5 class="info-date"><?php print date('F d, Y',$row->node_created);?><small><?php print date('H:i',$row->node_created);?></small></h5>
                <?php print $fields['picture']->content;?>
                <h5><?php print $node->name;?></h5>
            </div>
            <div class="post-body clearfix">
                <div class="blog-title">
                    <h1><?php print $fields['title']->content;?></h1>
                </div>
                <?php if(count($row->field_field_bl_thumbnail) > 1):?>
                <div class="flexslider">
                    <ul class="slides">
                        <?php foreach($row->field_field_bl_thumbnail as $key => $value):?>
                            <!-- Timeline item slide -->
                            <li>
                                <a href="<?php print $base_url.'/node/'.$row->nid;?>" class="zoom"> <img class="img-center img-responsive" src="<?php print image_style_url('blog_thumbnail',$value['rendered']['#item']['uri']);?>" alt=""/> </a>
                            </li>
                        <?php endforeach;?>
                    </ul>
                </div>
                <?php else:?>
                    <a href="<?php print $base_url.'/node/'.$row->nid;?>" class="zoom"><?php if(isset($row->field_field_bl_thumbnail[0])):?> <img src="<?php print image_style_url('blog_thumbnail',$row->field_field_bl_thumbnail[0]['rendered']['#item']['uri']);?>" class="img-responsive" alt=""><?php endif;?> </a>
                <?php endif;?>
                <div class="post-text">
                    <p class="lead">
                        <?php print $fields['field_bl_description']->content;?>
                    </p>
                </div>
            </div>
            <div class="post-arrow"></div>
        </div>
    </div>
</li>
<!-- Timeline item -->