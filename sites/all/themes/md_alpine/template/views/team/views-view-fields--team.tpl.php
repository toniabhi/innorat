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
$social = $row->field_field_team_socials;

?>
<!-- Team item -->
<div class="col-md-3 col-sm-3 col-md-3 col-xs-12">
    <div class="element-line">
        <div class="item_top">
            <div class="img-rounded team-element zoom">
                <div class="team-inner">
                    <div class="team-detail">
                        <div class="team-content">
                            <h3><strong><?php print $fields['title']->content;?></strong></h3>
                            <p>
                                <?php print $fields['field_team_job']->content;?>
                            </p>
                            <ul>
                                <?php foreach($social as $key => $value):
                                    $field_collection_val = $value['raw']['value'];
                                    $field_collection_item = $value['rendered']['entity']['field_collection_item'][$field_collection_val];
                                ?>
                                    <li>
                                        <a href="<?php print $field_collection_item['field_team_social_link'][0]['#markup'];?>"><i class="<?php print $field_collection_item['field_team_social_icon'][0]['#bundle'].' '.$field_collection_item['field_team_social_icon'][0]['#icon'];?> icon-2x"></i></a>
                                    </li>
                                <?php endforeach;?>
                            </ul>
                        </div>
                    </div>
                </div>
                <img src="<?php print image_style_url('team_thumbnail',$row->field_field_team_thumbnail[0]['rendered']['#item']['uri']);?>" alt="" class="img-responsive">
            </div>
        </div>
    </div>
</div>
<!-- Team item -->
