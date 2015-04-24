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
$node = node_load($row->nid);
?>
    <!-- Price col item -->
    <?php if($node->sticky == 1):?>
        <div class="item_top">
    <?php else:?>
    <div class="item_bottom">
    <?php endif;?>
        <div class="pricing-box">
            <div class="element-line">
                <?php if($node->sticky == 1):?>
                    <div class="pricing-featured">
                <?php endif;?>
                <ul>
                    <li class="title-row">
                        <h4><?php print $fields['title']->content;?></h4>
                    </li>
                    <li class="price-row">
                        <h1><?php print $fields['field_pc_currency']->content.$fields['field_pc_price']->content;?></h1><span>/<?php print $fields['field_pc_time']->content;?></span>
                    </li>
                    <?php foreach($row->field_field_pc_description as $key => $value):?>
                        <li>
                            <?php print $value['rendered']['#markup'];?>
                        </li>
                    <?php endforeach;?>
                    <li class="btn-row">
                        <div class="mybutton small">
                            <a href="<?php print $fields['field_pc_link']->content;?>"><span data-hover="<?php print $fields['field_pc_button_text_hover']->content;?>"><?php print $fields['field_pc_button_text']->content;?></span></a>
                        </div>
                    </li>
                </ul>
                <?php if($node->sticky == 1):?>
                    </div>
                <?php endif;?>
            </div>
        </div>
    </div>
    <!-- Price col item -->

