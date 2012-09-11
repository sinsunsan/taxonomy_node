<?php

/**
 * Implementation of hook_views_data().
 */
function taxonomynode_views_data() {
  $data = array();

  // Found the related term tid when we have the node nid in node view
  $data['taxonomynode']['table']['group'] = t('Taxonomy Node');

  // The join between taxonomynode table and node table (used in node view)
  $data['taxonomynode']['table']['join']['node'] = array(
      'left_field' => 'nid',
      'field' => 'nid',
  );
  
  // The join between taxonomynode table and term_data table (used in term view)
  $data['taxonomynode']['table']['join']['term_data'] = array(
      'left_field' => 'tid',
      'field' => 'tid',
  );
  
  // Define the nid field of taxonomynode table
  $data['taxonomynode']['nid'] = array(
    'group' => t('Taxonomy Node'),
    'title' => 'Node ID',
    'help' => t('Get the node linked with the term.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node linked to this term'),
    ),
   ); 
  
  // Define the tid field of taxonomynode table
  $data['taxonomynode']['tid'] = array(
    'group' => t('Taxonomy Node'),
    'title' => 'Term ID',
    'help' => t('Term ID (tid) of the mapping term of each node.'),
    'relationship' => array(
      'base' => 'term_data',
      'field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Term linked to this node'),
    ),
  );
  return $data;
}