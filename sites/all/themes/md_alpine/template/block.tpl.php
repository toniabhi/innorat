<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php
    $before_title = variable_get($block->delta.'_before_title');
    $after_title = variable_get($block->delta.'_after_title');
    $description = variable_get($block->delta.'_description');
    $tt_des_animate = variable_get($block->delta.'_title_des_animate');
    if($tt_des_animate != null) {
        if($tt_des_animate == 'none') {
            $tt_des_animate = '';
        }
    } else {
        $tt_des_animate = 'item_left';
    }

    $content_animate = variable_get($block->delta.'_content_animate');
    if($content_animate != null) {
        if($content_animate == 'none') {
            $content_animate = '';
        }
    } else {
        $content_animate = 'item_right';
    }

    $current_path = current_path();
    $region = $block->region;
?>
<?php if($region == 'header') :?>
    <?php print render($title_prefix); ?>
<?php print $content;?>
    <?php print render($title_suffix); ?>
<?php else:?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php if($block->delta != 'parallax_1' && $block->delta != 'parallax_2' && $block->delta != 'parallax_3' && $block->delta != 'parallax_4' && $block->delta != 'parallax_5' && $block->delta != 'parallax_6' && $block->delta != 'parallax_7' && $block->delta != 'header' && $block->delta != 'footer' && $block->delta != 'menu'):?>
        <div class="container">
            <div class="section-title text-center">
                <?php if(isset($before_title)):?>
                    <div class="<?php print $tt_des_animate;?>">
                        <span class="line big"></span>
                        <span ><?php print $before_title;?></span>
                        <span class="line big"></span>
                    </div>
                <?php endif?>
                <?php print render($title_prefix); ?>
                <?php if ($block->subject): ?>
                    <h1 class="<?php print $tt_des_animate;?>"><?php print $block->subject;?></h1>
                <?php endif;?>
                <?php print render($title_suffix); ?>
                <?php if(isset($after_title)):?>
                    <div class="<?php print $tt_des_animate;?>">
                        <span class="line"></span>
                        <span><?php print $after_title;?></span>
                        <span class="line"></span>
                    </div>
                <?php endif;?>
                <?php if(isset($description)):?>
                    <p class="lead <?php print $tt_des_animate;?>">
                        <?php print $description;?>
                    </p>
                <?php endif;?>
            </div>
        </div>
    <?php endif;?>
    <div class="content <?php print $content_animate;?>"<?php print $content_attributes; ?>>
        <?php print $content ;?>
    </div>
</div>
<?php endif;?>